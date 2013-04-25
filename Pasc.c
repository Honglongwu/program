#include <stdio.h>
#include <stdlib.h>

#define N 12

int main()
{
	int paca[N][N] = {0};
	int i, j;
	
	for (i = 0; i < N; ++i)
	{
		paca[i][0] = 1;
	}
	
	for (i = 1; i < N; ++ i)
	{
		for (j = 1; j <= i; ++j)
		{
			paca[i][j] = paca[i - 1][j - 1] + paca[i - 1][j];
		}
	}

	for (i = 0; i < N; ++ i)
	{
		for (j = 0; j <= N - i + 1; ++ j)
		{
			printf(" ");
		}
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", paca[i][j]);
		}
		printf("\n");
	}	
	return 0;
}

