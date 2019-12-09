#ifndef BUS_H
#define BUS_H 
#include <string>
#include <iostream>
#include "car_t.h"
using namespace std;

class bus_t : public car_t
{
public:
    bus_t();              //default CTOR
    ~bus_t();             //DTOR
    bus_t(const size_t);  //CTOR with capacity
    bus_t(const bus_t &); //copy CTOR

    void setNumofSeats(size_t);
    void setLineNum(size_t);
    size_t getNumofSeats() const;
    size_t getLineNumer() const;

private:
    size_t seats_number;
    size_t line_number;
    static size_t defNumofSeats;
    static size_t defNumofLine;
};
#endif