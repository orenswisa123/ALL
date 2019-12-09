#ifndef BINIO_T_CLASS_H
#define BINIO_T_CLASS_H
#include "virtIO_t.h"
#include <typeinfo>

class binIO_t : public virtIO_t
{
public:
    binIO_t() {}
    virtual ~binIO_t() {}
    binIO_t(string newName, string newMode) : virtIO_t(newName, newMode)
    {
        if ((m_mode != "r") && (m_mode != "r+") && (m_mode != "w") && (m_mode != "w+"))
        {
            m_status = bad_access_e;
            throw m_status;
        }
    }

    virtual binIO_t &operator>>(void *Buf);
    virtual binIO_t &operator<<(const void *Buf);
    void operator,(int lenght);

    virtual binIO_t &operator<<(int num);
    virtual binIO_t &operator>>(int &num);

    virtual binIO_t &operator<<(char c);
    virtual binIO_t &operator>>(char &c);

    virtual binIO_t &operator<<(float num);
    virtual binIO_t &operator>>(float &num);

    virtual binIO_t &operator<<(short num);
    virtual binIO_t &operator>>(short &num);

    virtual binIO_t &operator<<(long num);
    virtual binIO_t &operator>>(long &num);

    virtual binIO_t &operator<<(double num);
    virtual binIO_t &operator>>(double &num);

    virtual binIO_t &operator<<(unsigned int num);
    virtual binIO_t &operator>>(unsigned int &num);

    virtual binIO_t &operator<<(unsigned char c);
    virtual binIO_t &operator>>(unsigned char &c);

    virtual binIO_t &operator<<(unsigned short num);
    virtual binIO_t &operator>>(unsigned short &num);

    virtual binIO_t &operator<<(unsigned long num);
    virtual binIO_t &operator>>(unsigned long &num);

private:
    bool flag;
    void* m_buf;

    binIO_t(const binIO_t &t);            //copy CTOR
    binIO_t &operator=(const binIO_t &t); //operator =

    template <class T>
    binIO_t &get(T &t);

    template <class T>
    binIO_t &put(const T &t);
};

template <class T>
binIO_t &binIO_t::get(T &t)
{
    if (validRead())
    {
        *this >> &t, sizeof(T);
        return *this;
    }
    throw string("mode error.\n");
}

template <class T>
binIO_t &binIO_t::put(const T &t)
{
    if (vaildWrite())
    {
        *this << &t, sizeof(T);
        return *this;
    }
    throw string("file didnt open. \n");
}
#endif