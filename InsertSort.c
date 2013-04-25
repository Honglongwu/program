#include <stdio.h>
#include <stdlib.h>

void print_array(int arrary[], int len)
{
	int i ;
	for (i = 0; i < len; ++ i)
	{
		printf("%d\t",arrary[i]);
	}
	printf("\n");
}

int main()
{
	int a[4] = {4,2,3,1};
	int i, j;
	int length = 4;
	int tmp;
	for(i=1;i<length; ++i)
	{
		tmp = a[i];
		for(j=i; j>0 && tmp < a[j -1]; -- j)
		{
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
	print_array(a, length);
}

