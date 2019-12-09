#ifndef VIRTIO_T_CLASS_H
#define VIRTIO_T_CLASS_H
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class virtIO_t
{
public:
    typedef enum status
    {
        ok_e,
        cant_open_file_e,
        bad_access_e,
        writeErr_e,
        readErr_e
    } status;
    
    virtual ~virtIO_t() { Fclose(); }
    virtIO_t();
    virtIO_t(string, string);
    
    void Fclose()
    {
        if (m_fp != NULL)
        {
            fclose(m_fp);
        }  
    }
    void Print()const;
    void Fopen(const char*,const char*);
    virtual void setMode(string newMode) { m_mode = newMode; }
    size_t getfileLen() const;
    string getFileName() const { return m_name; }
    string getFileMode() const { return m_mode; }
    size_t getPosition() const { return m_pos; }
    void setPosition(size_t position);
    status getStatus() const { return m_status; }
    void setStatus(status tempstatus) { m_status = tempstatus; }
    bool validRead();
    bool vaildWrite();

    virtual virtIO_t &operator<<(int num)=0;
    virtual virtIO_t &operator>>(int &num)=0;
    virtual virtIO_t &operator<<(char c)=0;
    virtual virtIO_t &operator>>(char &c)=0;
    virtual virtIO_t &operator<<(float num)=0;
    virtual virtIO_t &operator>>(float &num)=0;
    virtual virtIO_t &operator<<(short num)=0;
    virtual virtIO_t &operator>>(short &num)=0;
    virtual virtIO_t &operator<<(long num)=0;
    virtual virtIO_t &operator>>(long &num)=0;
    virtual virtIO_t &operator<<(double num)=0;
    virtual virtIO_t &operator>>(double &num)=0;
    virtual virtIO_t &operator<<(unsigned int num)=0;
    virtual virtIO_t &operator>>(unsigned int &num)=0;
    virtual virtIO_t &operator<<(unsigned char c)=0;
    virtual virtIO_t &operator>>(unsigned char &c)=0;
    virtual virtIO_t &operator<<(unsigned short num)=0;
    virtual virtIO_t &operator>>(unsigned short &num)=0;
    virtual virtIO_t &operator<<(unsigned long num)=0;
    virtual virtIO_t &operator>>(unsigned long &num)=0;

private:
    virtIO_t(const virtIO_t &t);
    virtIO_t &operator=(const virtIO_t &t);

protected:
    FILE *m_fp;
    status m_status;
    string m_name;
    string m_mode;
    size_t m_pos;
};
#endif