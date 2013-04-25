#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = {10,3,2,18,93,600,8};
	int i, j;
	int length = 7;
	for (j = 1; j < length; ++ j)
	{
		for(i = 0; i < j - 1; i ++ )
		{
			int tmp;
			if(a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (i = 0; i < 7; ++ i)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}

