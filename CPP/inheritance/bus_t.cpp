#include <string>
#include <iostream>
#include "bus_t.h"

using namespace std;

size_t bus_t::defNumofSeats = 50;
size_t bus_t::defNumofLine = 10;

bus_t::bus_t()
{
    car_name = setCarName("bus");
    typeOfGear = setGear("standart");
    seats_number = defNumofSeats;
    line_number = defNumofLine;
}
bus_t::~bus_t()
{
}
bus_t::bus_t(size_t capa) : car_t(capa)
{
    car_name = setCarName("bus");
    typeOfGear = setGear("standart");
    seats_number = defNumofSeats;
    line_number = defNumofLine;
}
bus_t::bus_t(const bus_t &bus)
{
    capacity = bus.capacity;
    car_name = bus.car_name;
    typeOfGear = bus.typeOfGear;
    seats_number = bus.seats_number;
    line_number = bus.line_number;
}
void bus_t::setNumofSeats(size_t newNumofSeats)
{
    this->seats_number=newNumofSeats;
}
void bus_t::setLineNum(size_t newLineNum)
{
    this->line_number=newLineNum;
}
size_t bus_t::getNumofSeats() const
{
    return seats_number;
}
size_t bus_t::getLineNumer() const
{
    return line_number;
}