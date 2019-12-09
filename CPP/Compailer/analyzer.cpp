#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include<string>
#include "analyzer.h"
using namespace std;
string analyzer_t::s_predefinedTypesStrings[] =
	{"char", "short", "int", "long", "float", "double", "void"};
string analyzer_t::s_keyWordsStrings[] =
	{"if", "else", "for" , "while", "class", 
		"private", "public", "protected", "main", "const", "virtual"};
string analyzer_t::s_operatorsStrings[] =
	{"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};
string analyzer_t::s_predefTokensStrings[] =
	{"(", ")", "[", "]" , "{" , "}", ";", "<", ">" , "=", "+", "-", "*", "&"};

#define NUMOFELEM(ARR) (sizeof(ARR)/sizeof((ARR)[0]))

set<string> analyzer_t::s_predefinedTypes
	(s_predefinedTypesStrings, s_predefinedTypesStrings + NUMOFELEM(s_predefinedTypesStrings));
set<string> analyzer_t::s_keyWords
	(s_keyWordsStrings, s_keyWordsStrings + NUMOFELEM(s_keyWordsStrings));
set<string> analyzer_t::s_operators
	(s_operatorsStrings, s_operatorsStrings + NUMOFELEM(s_operatorsStrings));
set<string> analyzer_t::s_predefTokens
	(s_predefTokensStrings, s_predefTokensStrings + NUMOFELEM(s_predefTokensStrings));



void analyzer_t::initialAnalyzer()
{
    m_programStarted = false;
    m_predefTypeEncountered = false;
    m_curlyBracCount = 0;
    m_minus = 0;
    m_squareBracCount = 0;
    m_roundBracCount = 0;
    m_pointBracCount = 0;
    m_plus = 0;
    m_if = false;
}
static void PrintEnclErr(const char &brace, const int &countbrace)
{
    if (countbrace > 0)
    {
        cout << "error - " << brace << " '" << countbrace << "' not closed" << endl;
    }
}
void analyzer_t::completeAnalyze()
{
    m_if = false;

    PrintEnclErr('<', m_pointBracCount);
    PrintEnclErr('{', m_curlyBracCount);
    PrintEnclErr('[', m_squareBracCount);
    PrintEnclErr('(', m_roundBracCount);
}
bool analyzer_t::isValidVarName(const string &_token) const
{
    return (isalpha(_token[0]) || _token[0] == '_');
}

void analyzer_t::analyzeLine(tokenizer_t &t, size_t lineNum)
{
    vector<string>::iterator m_nextToken;
    m_nextToken = t.getVector().begin();

    while (m_nextToken != t.getVector().end())
    {
        analyzeToken(*(m_nextToken), lineNum);

        m_nextToken++;
    }
}
bool analyzer_t::EnclosureFuncCheck(const string& _token, const string& _open, const string& _close,int&counter,  size_t _lineNum)
{
	if(_close == _token)
	{
		if(0 < counter)
		{
			--counter;
		}else
		{
			cout<<"line "<<_lineNum<<": error - "<<_close<<" without "<<_open<<"\n"<<endl;
		}
		return true;
	}
	if(_open == _token)
	{
		++counter;
		
		return true;
	}
	return false;	
} 
bool analyzer_t::checkOperators(const string &_token, size_t _lineNum)
{
    if (_token == "+")
    {
        if (m_predefTypeEncountered)
        {
            cout << "line " << _lineNum << ": error - illgel var name error\n";
            m_predefTypeEncountered = false;
        }
        if (m_plus < 2)
        {
            m_plus++;
            m_minus = 0;
            return true;
        }
        else
        {
            cout << "line " << _lineNum << ": error - no operator +++"<<endl;
            m_plus=0;
            return true;
        }
        if (_token == "-")
        {
            if (m_predefTypeEncountered)
            {
                cout << "line " << _lineNum << ": error - illgel var name error\n"
                     << endl;
                m_predefTypeEncountered = false;
            }
            cout << "line " << _lineNum << ": error - no operator ";
            cout << _token << _token << _token << "\n"
                 << endl;
            this->m_plus = 0;
            return true;
        }
    }
    if (_token == "-")
    {
        if (m_minus < 2)
        {
            m_minus++;
            m_plus = 0;
            return true;
        }
        else
        {
            cout << "line " << _lineNum << ": error - no operator ";
            cout << _token << _token << _token << "\n"
                 << endl;
            this->m_minus = 0;
            return true;
        }
    }
    m_minus = 0;
    m_plus = 0;
    return false;
}

void analyzer_t::analyzeToken(const string &_token, size_t _lineNum)
{
    if (!m_programStarted)
    {
        if (_token != "main")
        {
            cout << "line " << _lineNum << ": error - the program doesn't start with 'main'\n"
                 << endl;
        }
        m_programStarted = true;
    }
    if (checkOperators(_token, _lineNum))
    {
        return;
    }
    if ((EnclosureFuncCheck(_token,"(",")",m_roundBracCount,_lineNum) ||
		EnclosureFuncCheck(_token,"[","]",m_squareBracCount,_lineNum) ||
		EnclosureFuncCheck(_token,"{","}",m_curlyBracCount,_lineNum) || CheckEnclosureIFELSE(_token, _lineNum)))
    {
        return;
    }
    if (s_predefinedTypes.find(_token) != s_predefinedTypes.end())
    {
        if (m_predefTypeEncountered)
        {
            cout << "line " << _lineNum << ": error - multiple type declaration\n"
                 << endl;
            m_predefTypeEncountered = false;
        }
        else
        {
            m_predefTypeEncountered = true;
        }
        return;
    }
    if (m_predefTypeEncountered)
    {
        if (s_keyWords.find(_token) != s_keyWords.end() ||
            s_operators.find(_token) != s_operators.end() ||
            s_predefTokens.find(_token) != s_predefTokens.end())
        {
            cout << "line " << _lineNum << ": error - illegal variable name\n"
                 << endl;
        }
        else
        {
            if (m_symbolTable.find(_token) != m_symbolTable.end())
            {
                cout << "line " << _lineNum << ": error - variable '" << _token << "' already declared\n"
                     << endl;
            }
            else
            {
                if (isValidVarName(_token))
                {
                    m_symbolTable.insert(_token);
                }
                else
                {
                    cout << "line " << _lineNum << ": error - illegal variable name\n"
                         << endl;
                }
            }
        }
        m_predefTypeEncountered = false;
    }
    else
    {
        if (!(s_keyWords.find(_token) != s_keyWords.end() ||
            s_operators.find(_token) != s_operators.end() ||
            s_predefTokens.find(_token) != s_predefTokens.end()) &&
            isValidVarName(_token) &&
            m_symbolTable.find(_token) == m_symbolTable.end())
        {
            cout << "line " << _lineNum << ": error - " << _token << " is not declared\n"
                 << endl;
        }
    }
}

bool analyzer_t::CheckEnclosureIFELSE(const string &_token, size_t _lineNum)
{
    if (_token == "else")
    {
        if (m_if == false)
        {
            cout << "line " << _lineNum << ": error - there is else without if\n"
                 << endl;
            return true;
        }
        return true;
    }
    if (_token == "if")
    {
        m_if = true;
        return true;
    }
    return false;
}