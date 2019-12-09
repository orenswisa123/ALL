#include "binIO_t.h"

binIO_t &binIO_t::operator>>(void *Buf)
{
    flag = true; //read from file
    m_buf=Buf;
    return *this;
}
binIO_t &binIO_t::operator<<(const void *Buf)
{
    flag = false; //write to file
    m_buf=(void*)Buf;
    return *this;
}
void binIO_t::operator,(int lenght) 
{
    if (flag == false)
    {
        fwrite(m_buf ,lenght,1, m_fp);
    }
    else
    {
        fread(m_buf,lenght,1,m_fp);
    }
    
    
}

binIO_t &binIO_t::operator<<(int num) { return put(num); }
binIO_t &binIO_t::operator>>(int &num) { return get(num); }
binIO_t &binIO_t::operator<<(char c) { return put(c); }
binIO_t &binIO_t::operator>>(char &c) { return get(c); }
binIO_t &binIO_t::operator<<(unsigned char uc) { return put(uc); }
binIO_t &binIO_t::operator>>(unsigned char &uc) { return get(uc); }
binIO_t &binIO_t::operator<<(short s) { return put(s); }
binIO_t &binIO_t::operator>>(short &s) { return get(s); }
binIO_t &binIO_t::operator<<(float f) { return put(f); }
binIO_t &binIO_t::operator>>(float &f) { return get(f); }
binIO_t &binIO_t::operator<<(unsigned short us) { return put(us); }
binIO_t &binIO_t::operator>>(unsigned short &us) { return get(us); }
binIO_t &binIO_t::operator<<(unsigned int num) { return put(num); }
binIO_t &binIO_t::operator>>(unsigned int &num) { return get(num); }
binIO_t &binIO_t::operator<<(long int num) { return put(num); }
binIO_t &binIO_t::operator>>(long int &num) { return get(num); }
binIO_t &binIO_t::operator<<(unsigned long int num) { return put(num); }
binIO_t &binIO_t::operator>>(unsigned long int &num) { return get(num); }
binIO_t &binIO_t::operator<<(double num) { return put(num); }
binIO_t &binIO_t::operator>>(double &num) { return get(num); }