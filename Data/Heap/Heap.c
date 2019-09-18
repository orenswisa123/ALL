#include <stdio.h>
int end;

void swap(int *x, int *y)
{
	*x = (*x * *y) / (*y = *x);
}
int LEFT(int i)
{
	return (2 * i + 1);
}

int RIGHT(int i)
{
	return (2 * i + 2);
}
void Heapify(int A[], int i)
{
	int left = LEFT(i);
	int right = RIGHT(i);
	int largest = i;
	if (left < end && A[left] > A[i])
		largest = left;
	if (right < end && A[right] > A[largest])
		largest = right;
	if (largest != i) 
	{
		swap(&A[i], &A[largest]);
		Heapify(A, largest);
	}
}
void BuildHeap(int A[])
{
	int i = (end - 2) / 2;
	while (i >= 0)
		Heapify(A, i--);
}

void HeapSort(int A[], int n)
{
	end = n;
	BuildHeap(A);
	while (end != 1) 
	{
		swap(&A[0], &A[end - 1]);
		end--;
		Heapify(A, 0);
	}
}
int main(void)
{
	int A[] = { 6, 4, 7, 1, 9, -2 };
	int n = sizeof(A) / sizeof(A[0]);
	HeapSort(A, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", A[i]);
	return 0;
}