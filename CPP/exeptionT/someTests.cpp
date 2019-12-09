#include <iostream>
#include <string>
#include <typeinfo>
#include "exep.h"
using namespace std;

string str = "Everything OK!";

void ifPositive(int num)
{
    if (num < 0)
    {
        string fileName(__FILE__);
        TException_t<int> TExep(__LINE__, fileName, num, "The number is negative");
        throw TExep;
    }
    throw str;
}

void ifLetter(char ch)
{
    if (!isalpha(ch))
    {
        string fileName(__FILE__);
        TException_t<char> TExep(__LINE__, fileName, ch, "The char is not letter");
        throw TExep;
    }
    throw str;
}