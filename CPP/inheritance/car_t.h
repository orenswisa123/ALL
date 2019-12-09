#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
using namespace std;

class car_t
{
public:
    enum Gear {Standart,Automatic};
    
    car_t(); //default CTOR
    car_t(const size_t);  //CTOR with capacity

    


    string setCarName(const string);
    string setGear(const string);
    const string& getCarName()const {return car_name;}
    size_t getCapacity()const {return capacity;}

    
    bool operator<(const car_t &car);
    bool operator==(const car_t &car);

protected:
    car_t &operator=(const car_t &car);
    car_t(const car_t &); //copy CTOR
    ~car_t(); //DTOR
    size_t capacity;
    string car_name;
    string typeOfGear;
    static size_t car_id;
    static size_t defCapacity;
    private:
    const size_t id;
    

};
#endif