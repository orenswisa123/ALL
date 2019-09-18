#include <stdio.h>
#include<stddef.h>

int sumNums(int *arr,size_t size);
#define ARR_SIZE 4

int main()
{
    int arr[ARR_SIZE]={4,7,5,2};
    int result=-1;

    result=sumNums(arr,ARR_SIZE);
    printf("sum:%d\n",result);
}

int sumNums(int *arr,size_t size)
{
    if(size==1)
    {
        return (arr[size-1]);
    }
    else
    {
        {
            return (sumNums(arr,size-1) + arr[size-1]);
        }
    }
    
}