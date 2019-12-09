#include <string>
#include <iostream>
#include "car_t.h"
using namespace std;
size_t car_t::car_id = 0;
size_t car_t::defCapacity = 1500;

car_t::car_t() : id(car_id++)
{
}
car_t::~car_t()
{
}
car_t::car_t(const size_t capa) : id(car_id++)
{
    capacity = capa;
}
car_t::car_t(const car_t &car) : id(car_id++)
{
    capacity = car.capacity;
    car_name = car.car_name;
    typeOfGear = car.typeOfGear;
}

string car_t::setCarName(string carName)
{
    return carName;
}
string car_t::setGear(string gearType)
{
    return gearType;
}
/*const string& car_t::getCarName()const
{
    return car_name;
}*/
bool car_t::operator==(const car_t &car)
{
    if(car.car_name.compare(car_name))
    return true;
    else return false;
}
bool car_t::operator<(const car_t &car)
{
    if(car.capacity<capacity)
    return true;
    else
    {
        return false;
    }
    
}