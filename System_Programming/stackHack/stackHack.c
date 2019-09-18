#include <stdio.h>

void B()
{
    printf("hey im B\n");
}
int A(int num)
{
    /*void(*func_ptr)(void)=B;*/
    *(&num-1)=B;
    printf("this A func\n");
    return 0;
}
int main()
{
    int a;
    a=A(5);
    return 1;
}
