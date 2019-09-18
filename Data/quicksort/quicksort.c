#include <stdio.h>
#include<stdlib.h>

int partition (int arr[], int low, int high) ;
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);
void swap(int *xp, int *yp);

int main()
{
    int arr[10]={3,5,9,1,4,8,2,11,18,7};
    quickSort(arr, 0, 10-1); 
    printf("Sorted array: "); 
    printArray(arr, 10); 
    return 0; 
}
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    } 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
    int j;
    for(j = low; j <= high - 1; j++)
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp;
}