#ifndef EXEP_H
#define EXEP_H
#include <iostream>
#include <string>
using namespace std;

template <class exep>
class TException_t
{
public:
    TException_t(int lineNumber, string fileName, exep object, string message)
    {
        m_line_number = lineNumber;
        m_file_name = fileName;
        m_object = object;
        m_message = message;
    };
    ~TException_t(){};

    const int& getLineNumber() const { return m_line_number; };
    const string& getFileName() const { return m_file_name; };
    const exep& getExeptionObject() const { return m_object; };
    const string& getMessage() const { return m_message; };

private:
    int m_line_number;
    string m_file_name;
    exep m_object;
    string m_message;
};
#endif