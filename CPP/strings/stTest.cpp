#include <iostream>
#include <string.h>
#include "string_t.h"
using namespace std;

int main()
{
    string_t str1;
    char str_temp[256] = "Oren";
    cout << "set string: \n";
    string_t str2(str_temp);
    cin >> str2;
    str1=str2;
    return 1;
}