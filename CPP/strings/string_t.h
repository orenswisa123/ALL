#include <string.h>
#include<iostream>
using namespace std;
class string_t
{
public:
    ~string_t(); //DTOR
    string_t(); //default COTR
    string_t(const string_t& str); //copy COTR
    string_t(const char*); // COTR
    string_t& operator=(const string_t & str); 

    inline int getLen() const; //get length
    void setString(const char*); //set string
    const char* getString() const; //getstring
    int compare(const char*) const; //compare 2 string
    void printString();

    void toUppercase();
    void toLowercase();
    void preprend(const char*);
    void preprend(const string_t &);
    string_t& operator+=(const char* str);
    string_t& operator+=(const string_t & str_t);
    bool operator<(const string_t & str_t) const;
    bool operator>(const string_t & str_t) const;
    bool operator==(const string_t & str_t) const;
    bool operator!=(const string_t & str_t) const;
    bool operator<=(const string_t & str_t) const;
    bool operator>=(const string_t & str_t) const;
    bool contains(const char*) const;
    char operator[](size_t) const;
    char& operator[](size_t);


    size_t getCapacity()const;
    size_t setDefCapacity(size_t);
    inline static size_t getDefCapacity();
    static bool setCaseSens(bool);
    static bool getcaseSensMode();
    int firstChar(const char c) const;
    int lastChar(const char c) const;
    string_t operator()(size_t n1,size_t n2)const;
    static size_t getCount(); 


private:
    char* string;
    int len;
    static bool caseSens; //if true then S != s
    size_t capacity;
    static size_t defCap;
    char* createString(const char*);
    static size_t countStrings;
    static size_t nextPowerOf2(size_t n);
};
ostream& operator<<(ostream& os,const string_t& str_t);
istream& operator>>(istream& is, string_t& str_t);

inline size_t string_t::getDefCapacity() {return defCap;}
inline int string_t::getLen()const {return len;}

