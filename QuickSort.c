//made by wu
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define swap(x, y)  {int t; t = x; x = y; y = t;}

void print(int [], int);
int partition(int [], int, int);
void quicksort(int [], int, int);

int main()
{
	int number[MAX] = {0};
	int i;
	
	srand(time(NULL));
	
	printf("pre-order:\n");
	for(i = 0; i < MAX; ++ i)
	{
		number[i] = rand() % 100;
	}

	print(number, MAX);
		
	quicksort(number, 0, MAX - 1);
	printf("pos-order:\n");
	print(number, MAX);
	
	return 0;
}

int partition(int array[], int left, int right)
{
	int l, r, pivot;
	l = left + 1;
	r = right;
	pivot = array[left];
	
	while(1)
	{
		while(l < right + 1 && array[l] < pivot){l ++;}
		while(r > 0 && array[r] > pivot){r --;}
		if(l > r)
		{
			break;
		}
		swap(array[l], array[r]);		
	}
	array[left] = array[r];
	array[r] = pivot;
	return r;
}

void quicksort(int array[], int left, int right)
{
	int item;

	if(left < right)
	{
		item = partition(array, left, right);
		quicksort(array, left, item -1);
		quicksort(array, item + 1, right);
	}
}

void print(int array[], int num)
{
	int i;
	for(i = 0; i < num; ++ i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}

