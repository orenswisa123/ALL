#ifndef memPage_t_H
#define memPage_t_H
#include "memManager_t.h"
//#include<cstdlib>
using namespace std;

class memPage_t : public memManager_t
{
public:
    memPage_t();
    virtual ~memPage_t();
    memPage_t(size_t capa);

    size_t getCapacity() const { return capacity; }
    virtual bool isMemEmpty() const;
    virtual bool isMemFull() const;
    virtual size_t write(const void *, size_t); //we get number of bytes
    virtual size_t write(const void *, size_t, size_t);
    virtual size_t read(void *, size_t); //return num of success bytes read
    virtual size_t read(void *, size_t, size_t);
   /* static size_t getDefCapacity();
    static void setDefCapacity(size_t cap);*/

private:
    size_t capacity;
    static size_t defCapacity;
    memPage_t(const memPage_t &mp) {}
    memPage_t &operator=(const memPage_t &mp) {}
    char *buffer;
};
#endif