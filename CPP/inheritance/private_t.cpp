#include <string>
#include <iostream>
#include "private_t.h"
using namespace std;

size_t private_t::defSpeed=0;

private_t::private_t()
{
    car_name = setCarName("private");
    typeOfGear = setGear("automatic");
    speed=defSpeed;
}
private_t::~private_t()
{
}
private_t::private_t(const size_t capa)
{
    car_name = setCarName("private");
    typeOfGear = setGear("automatic");
    speed=defSpeed;
}
private_t::private_t(const private_t &Pcar)
{
    car_name = setCarName("private");
    typeOfGear = setGear("automatic");
    speed=Pcar.speed;
}
void private_t::accelerate()
{
    speed=speed+10;
}
void private_t::reduceSpeed()
{
    speed=speed-10;
}
size_t private_t::getSpeed()const
{
    return speed;
}
void private_t::setdefSpeed(size_t newSpeed)
{
    defSpeed=newSpeed;
}