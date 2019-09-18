#include<stdio.h>

    struct sta
    {
         char c;
         char c2;
         int i2;
        int i;
    };
int main()
{
    struct sta s1;
    printf("%ld\n" , sizeof(s1));
    
}