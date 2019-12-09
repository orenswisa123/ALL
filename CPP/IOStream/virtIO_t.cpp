#include "virtIO_t.h"

virtIO_t::virtIO_t()
{
    m_fp = NULL;
    m_name;
    m_mode;
    m_status = ok_e;
    m_pos = 0;
}
virtIO_t::virtIO_t(string newName, string newMode)
{
    m_fp = NULL;
    m_name = newName;
    m_mode = newMode;
    m_status = ok_e;
    m_pos = 0;
}
void virtIO_t::Print()const
{
    cout<<"Status:"<<m_status<<endl;
    cout<<"File name:" <<m_name<<endl;
    cout<<"Mode:"<<m_mode<<endl;
}

void virtIO_t::Fopen(const char* name,const char* mode)
{
    m_fp = fopen(name, mode);
    if (!m_fp)
    {
        m_status = cant_open_file_e;
        throw string("Can't open file");
    }
}
size_t virtIO_t::getfileLen() const
{
    size_t lenght = 0, currPosition = ftell(m_fp);

    if (m_fp)
    {
        fseek(m_fp, 0, SEEK_END);
        lenght = ftell(m_fp);
        fseek(m_fp, currPosition, SEEK_SET);
    }
    return lenght;
}
void virtIO_t::setPosition(size_t position)
{
    if (m_fp)
    {
        m_pos = position;
    }
}
bool virtIO_t::validRead()
{
    bool isValid = true;
    if (!m_fp && m_mode != "r" && m_mode != "r+" && m_mode != "w+")
    {
        m_status = bad_access_e;
        isValid = false;
    }
    return isValid;
}
bool virtIO_t::vaildWrite()
{
    bool isValid = true;
    if (!m_fp && m_mode != "w" && m_mode != "w+" && m_mode != "r+")
    {
        m_status = bad_access_e;
        isValid = false;
    }
    return isValid;
}
