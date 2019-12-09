#include<iostream>

class A{
    public:
    A * myA;
};

int main()
{
    A a;
    A c;
    a.myA=&c;
}