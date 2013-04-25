#include <stdio.h>
#include <stdlib.h>

#define N 20

int main()
{
	int Fibonacci[N] = {0};
	Fibonacci[0] = 1;
	Fibonacci[1] = 1;

	int i;
	for (i = 2; i < N; ++ i)
	{
		Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
	}
	for (i = 0; i < N; ++ i)
	{
		printf("%d\t", Fibonacci[i]);
	}
	printf("\n");
	
	return 0;
}

