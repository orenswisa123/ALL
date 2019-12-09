#ifndef PARSER_T_H
#define PARSER_T_H
#include <fstream>
#include "analyzer.h"
#include "tokenizer.h"

using namespace std;

class parser_t
{
public:
    parser_t();
    ~parser_t();
    void parserFile(const string &fileName);

private:
    parser_t(const parser_t &t);
    const parser_t &operator=(const parser_t &t);
    ifstream m_file;
    tokenizer_t *m_tokenizer;
    analyzer_t *m_analyzer;
};

#endif