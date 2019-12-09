#ifndef PRIVATE_H
#define PRIVATE_H 
#include <string>
#include <iostream>
#include "car_t.h"
using namespace std;

class private_t : public car_t
{
public:
    private_t();              //default CTOR
    ~private_t();                 //DTOR
    private_t(const size_t);  //CTOR with capacity
    private_t(const private_t &); //copy CTOR

    void accelerate();
    void reduceSpeed();
    size_t getSpeed()const;
    void setdefSpeed(size_t);

private:
    size_t speed;
    static size_t defSpeed;
};
#endif