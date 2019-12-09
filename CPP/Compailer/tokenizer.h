#ifndef TOKENIZER_T_H
#define TOKENIZER_T_H
#include <string>
#include <vector>
#include<iterator>
#include<set>
using namespace std;

class tokenizer_t
{
public:
    tokenizer_t() {}
    virtual ~tokenizer_t() {}
    void tokenize(const string&);
    size_t getSize() const { return m_tokens.size(); }
    const string &getNextToken();
    vector<string> &getVector() { return m_tokens; }
    

private:
    tokenizer_t(const tokenizer_t &t);
    tokenizer_t &operator=(const tokenizer_t &t);
    vector<string> m_tokens;
    vector<string>::iterator m_nextToken;

	static const char s_tokensDelimitersArr[];
	static const char s_blankDelimitersArr[];
	static const string s_emptyString;
	
	static const set<char> s_tokensDelimiters ;	
	static const set<char> s_blankDelimiters ;
	
};

#endif // !TOKENIZER_T_H
