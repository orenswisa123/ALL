#include<stdio.h>
int sort_01_func(int ,int*);
int main()
{
	int *ptr;
	int size=7;
	int a[7]={1,0,1,0,1,1,0};
	ptr=&a[0];
	sort_01_func(size,ptr);
}


int sort_01_func(int size,int *ptr)
{
	int i,j,temp;
        for (i = 0;i<size;i++) 
        {
            for (j = i + 1; j<size; ++j)
            {
                if (ptr[i] > ptr[j]) 
                {
                    temp =  ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = temp;
                }
            }

        }
	return 1;
}
