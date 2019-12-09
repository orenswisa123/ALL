#include <iostream>

int main()
{
    try
    {
        throw;
    }
    catch(...)
    {
        std::cout<<"c";
    }
    
}