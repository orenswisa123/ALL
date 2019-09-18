#include <stdio.h>
#include <stdlib.h> 
void sort4(int*,int);
int main() 
{
	int arr4[8]={1,-5,4,7,-1,0,-8,5};
	int i;


	sort4(arr4,8);

	printf("\n");
	printf("sort even and odd with the same order:\n");

	for(i=0;i<8;i++)
	{
		printf("%d",arr4[i]);
	}

   
	return 0;

}


void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}

void sort4(int arr[],int n)
{ 
   int i, j;
   int flag=0; 
   for (i = 0; i < n-1; i++){
   	   flag =0;          
       for (j = 0; j < n-i-1; j++)
       { 
           if ((abs(arr[j])%2!=0)&&(abs(arr[j+1])%2==0))
            {
              swap(&arr[j], &arr[j+1]);
              flag=1;
            }
       }
    if(flag==0) break; 
    }
}


