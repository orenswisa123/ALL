#ifndef ANALYZER_T_H
#define ANALYZER_T_H
#include <vector>
#include <set>
#include <string>
#include "tokenizer.h"

using namespace std;

class analyzer_t
{
public:
    analyzer_t(){};
    void initialAnalyzer();
    void analyzeLine(tokenizer_t &t, size_t lineNum);
    void completeAnalyze();
    bool getTypeEncount() const { return m_predefTypeEncountered; }
    bool getProgramStarted() const { return m_programStarted; }
    void setType(bool flag) { m_predefTypeEncountered = flag; }
    void setProgStart(bool flag) { m_programStarted = flag; }

private:
    //non-copyable
    analyzer_t(const analyzer_t &t);
    const analyzer_t &operator=(const analyzer_t &t);

	static set<string> s_predefinedTypes;
	static set<string> s_keyWords;
	static set<string> s_operators;
	static set<string> s_predefTokens;
	
	static  string s_predefinedTypesStrings[];
	static  string s_keyWordsStrings[];
	static  string s_operatorsStrings[];
	static  string s_predefTokensStrings[];

    int m_roundBracCount;  //()
    int m_curlyBracCount;  //{}
    int m_squareBracCount; //[]
    int m_pointBracCount;  //<>
    int m_minus;           //-
    int m_plus;            //+
    bool m_if = false;
    bool m_programStarted;
    bool m_predefTypeEncountered;
    set<string> m_symbolTable;
    void analyzeToken(const string &_token, size_t _lineNum);

    bool isValidVarName(const string &_token) const;

    //bool CheckEnclosure(const string &_token, size_t _lineNum);

    bool checkOperators(const string &_token, size_t _lineNum);
    bool CheckEnclosureIFELSE(const string &_token, size_t _lineNum);
    bool EnclosureFuncCheck(const string &_token, const string& _open, const string& _close, int &counter, size_t _lineNum);
};
#endif
