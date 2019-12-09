#include <stdexcept>
#include "parser.h"

parser_t::parser_t() : m_analyzer(new analyzer_t), m_tokenizer(new tokenizer_t) {}

parser_t::~parser_t()
{
    delete m_tokenizer;
    delete m_analyzer;
}
void parser_t::parserFile(const string &fileName)
{
    m_file.open(fileName.c_str());
    if (!m_file.good())
    {
        throw runtime_error("file not exist!");
    }
    m_analyzer->initialAnalyzer();
    string nextLine;
    size_t lineNumber = 1;
    while (getline(m_file, nextLine))
    {
        m_tokenizer->tokenize(nextLine);
        if (m_tokenizer->getSize() > 0)
        {
            m_analyzer->analyzeLine(*m_tokenizer, lineNumber);
        }
        lineNumber++;
    }
    m_analyzer->completeAnalyze();
    m_file.close();
}