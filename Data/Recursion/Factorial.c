#include <stdio.h>

unsigned int factorial(unsigned int n);

int main()
{
    unsigned int x=0;
    unsigned int result=0;
    printf("enter number:\n");
    scanf("%u", &x);

    result=factorial(x);
    printf("%u is the factorial of %u \n" ,result,x);

}



unsigned int factorial(unsigned int n)
{
    if(n>=1)
    {
        return factorial(n-1)*n;
    }
    else
    {
        return 1;
    }
}

