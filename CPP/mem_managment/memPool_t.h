#ifndef memPool_t_H
#define memPool_t_H
#include "memPage_t.h"
#include <vector>
using namespace std;

class memPool_t : public memManager_t
{
public:
    memPool_t()
    {
        memPage_t *pg = new memPage_t;
        v.insert(v.end(), pg);
        pageSize=pg->getCapacity();
    }
    virtual ~memPool_t()
    {
        for (int i = 0; i < v.size(); i++)
        {
            delete v[i];
        }
    }
    virtual bool isMemEmpty() const;
    virtual bool isMemFull() const{return true;}
    virtual size_t write(const void *, size_t); //we get number of bytes
    virtual size_t write(const void *, size_t, size_t);
    virtual size_t read(void *, size_t); //return num of success bytes read
    virtual size_t read(void *, size_t, size_t);

private:
    size_t pageSize;
    vector<memPage_t *> v;
    memPool_t(const memPool_t &mp) {}
    memPool_t &operator=(const memPool_t &mp);
    
};
#endif