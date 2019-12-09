#include "string_t.h"
#include <string.h>
#include <iostream>
using namespace std;

static size_t nextPowerOf2(size_t n);

size_t string_t::defCap = 8;
size_t string_t::countStrings = 0;
bool string_t::caseSens = true;

string_t::string_t()
{
    string=createString(0);
}
string_t::~string_t()
{
    delete[] string;
    len=0;
}
string_t::string_t(const string_t &str)
{
    string=createString(str.string);
}
string_t::string_t(const char *str)
{
    createString(0);
    string=createString(str);
}
/*int string_t::getLen() const
{
    return len;
}*/
const char *string_t::getString() const
{
    return this->string;
}
void string_t::setString(const char *str)
{
    delete[] string;
    string=createString(str);
}
string_t &string_t::operator=(const string_t &str)
{
    if (this != &str)
    {
        delete[] this->string;
        len=0;
        createString(str.string);
    }
    return *this;
}
int string_t::compare(const char *str1) const
{
    if (caseSens == true)
    {
        int c = strcmp(string, str1);
        return c == 0 ? 0 : c < 0 ? 1 : 2;
    }
    if (caseSens == false)
    {
        int answer;
        answer = strcasecmp(string, str1);
        return answer == 0 ? 0 : answer < 0 ? 1 : 2;
    }
}
char *string_t::createString(const char *str)
{
    if (str == 0)
    {
        capacity = defCap;
        string = new char[capacity];
        string[0] = '\0';
    }
    else
    {
        if (strlen(str) > capacity)
        {
            capacity = nextPowerOf2(strlen(str) + 1);
            string = new char[capacity];
        }
        strcpy(string, str);
        len = strlen(str);
    }
    countStrings++;
    return string;
}
void string_t::printString()
{
    cout << string << endl;
}
void string_t::toUppercase()
{
    int i;
    for (i = 0; i < this->len; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i] = string[i] - 32;
    }
}
void string_t::toLowercase()
{
    int i;
    for (i = 0; i < this->len; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
            string[i] = string[i] + 32;
    }
}
void string_t::preprend(const char *str)
{
    if (str != NULL)
    {
        char *temp = new char[strlen(str) + this->len + 1];
        strcpy(temp, str);
        strcat(temp, this->string);
        delete[] this->string;
        this->string = temp;
        this->len = strlen(this->string);
    }
}
void string_t::preprend(const string_t &str_t)
{
    preprend(str_t.string);
}
string_t &string_t::operator+=(const char *str)
{
    if (str != NULL)
    {
        char *temp = new char[strlen(str) + this->len + 1];
        strcpy(temp, this->string);
        strcat(temp, str);
        delete[] this->string;
        this->string = temp;
        this->len = strlen(this->string);
    }
    return *this;
}
string_t &string_t::operator+=(const string_t &str_t)
{
    *this += str_t.string;
}
bool string_t::operator<(const string_t &str_t) const
{
    if (strcmp(this->string, str_t.string) < 0)
    {
        return true;
    }
    return false;
}
bool string_t::operator>(const string_t &str_t) const
{
    if (strcmp(this->string, str_t.string) > 0)
    {
        return true;
    }
    return false;
}
bool string_t::operator==(const string_t &str_t) const
{
    if (strcmp(this->string, str_t.string) == 0)
        return true;
    return false;
}
bool string_t::operator!=(const string_t &str_t) const
{
    if (strcmp(this->string, str_t.string) != 0)
        return true;
    return false;
}
bool string_t::operator<=(const string_t &str_t) const
{
    if (strcmp(this->string, str_t.string) <= 0)
    {
        return true;
    }
    return false;
}
bool string_t::operator>=(const string_t &str_t) const
{
    if (strcmp(this->string, str_t.string) >= 0)
    {
        return true;
    }
    return false;
}
bool string_t::contains(const char *str) const
{
    if (strstr(string, str) != NULL)
    {
        return true;
    }
    return false;
}
char string_t::operator[](size_t index) const
{
    if (index <= this->len)
    {
        return this->string[index];
    }
    else
    {
        cout << "out on bound \n";
        return this->string[len];
    }
}
char &string_t::operator[](size_t index)
{
    if (index > this->len)
    {
        cout << "out on bound \n";
        return this->string[len];
    }
    return this->string[index];
}
ostream &operator<<(ostream &os, const string_t &str_t)
{
    os << "string: " << str_t.getString() << endl
       << "length: " << str_t.getLen() << endl;
    return os;
}
istream &operator>>(istream &is, string_t &str_t)
{
    char str[64];
    is >> str;
    str_t.setString(str);
    return is;
}
size_t string_t::getCapacity() const
{
    return capacity;
}
size_t string_t::setDefCapacity(size_t newCapacity)
{
    newCapacity = nextPowerOf2(newCapacity);
    size_t oldCapacity = defCap;
    defCap = newCapacity;
    return oldCapacity;
}
//size_t string_t::getDefCapacity() const { return defCap; }

bool string_t::setCaseSens(bool flag)
{
    bool temp = caseSens;
    caseSens = flag;
    return temp;
}
bool string_t::getcaseSensMode()
{
    return caseSens;
}
int string_t::firstChar(const char c) const
{
    int i;
    bool flag = false;
    for (i = 0; i <= len; i++)
    {
        if (string[i] == c)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        return i + 1;
    }
    else
    {
        cout << "\n Sorry!! We haven't found the Search Character " << c;
        return len;
    }
}

int string_t::lastChar(const char c) const
{
    int i;
    bool flag = false;
    for (i = len; i >= 0; i--)
    {
        if (string[i] == c)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        return i + 1;
    }
    else
    {
        cout << "\n Sorry!! We haven't found the Search Character " << c;
        return len;
    }
}

string_t string_t::operator()(size_t n1, size_t n2) const
{
    string_t s;
    if(n1 < this->len)
    {
        char* tmp = new char[this->len];
        strncpy(tmp, this->string + n1, n2);
        s.setString(tmp);
        delete[] tmp;
    }
    return s;
}
size_t string_t::getCount()
{
    return countStrings;
}

size_t string_t::nextPowerOf2(size_t n)
{
    size_t count = 0;
    if (n && !(n & (n - 1)))
        return n;
    while (n != 0)
    {
        n >>= 1;
        count += 1;
    }
    return 1 << count;
}
