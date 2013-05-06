#include <stdio.h>
#include <stdlib.h>

int travel(int, int);
int board[8][8] = {0};

int main()
{
	int startx, starty;
	int i, j;
	printf("please input the start position:");
	scanf("%d %d", &startx, &starty);
	
	if(travel(startx, starty))
	{
		printf("finished\n");
	}else
	{
		printf("failed\n");
	}
	for(i = 0; i < 8; i ++)
	{
		for(j = 0; j < 8; j ++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int travel(int x, int y)
{
	// these eight directions of knights travel
	int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, 1};
	int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	
	// test the next direction
	int nexti[8] = {0};
	int nextj[8] = {0};
	// record the number of path
	int exists[8] = {0};
	int i, j, k, m, l;
	int tmpi, tmpj;
	int tmp, min, count;

	i = x;
	j = y;
	board[i][j] = 1;
	
	for(m = 2; m <= 64; m ++)
	{
		for(l = 0; l < 8; l ++)
		{
			exists[l] = 0;
		}
		
		l = 0;
		// test eight directions
		for(k = 0; k < 8; k ++)
		{
			tmpi = i + ktmove1[k];
			tmpj = j + ktmove2[k];
			
			// out of region
			if(tmpi < 0 || tmpj < 0 || tmpi > 7 | tmpj > 7)
			{
				continue;
			}
			// access to the region
			if(board[tmpi][tmpj] == 0)
			{
				nexti[l] = tmpi;
				nextj[l] = tmpj;
				l ++;
			}
		}
		count = l;
		
		if(count == 0)
		{
			return 0;
		}else if(count == 1)
		{
			min = 0;
		}else
		{
			for(l = 0; l < count; l ++)
			{
				for (k = 0; k < 8; k ++)
				{
					tmpi = nexti[l] + ktmove1[k];
					tmpj = nextj[l] + ktmove2[k];
					if(tmpi < 0 || tmpj < 0 || tmpi > 7 || tmpj > 7)
					{
						continue;
					}
					if(board[tmpi][tmpj] == 0)
					{
						exists[l] ++;
					}
				}
			}
			tmp = exists[0];
			min = 0;
			
			for(l = 1; l < count; l ++)
			{
				if(exists[l] < tmp)
				{
					tmp = exists[l];
					min = l;
				}
			}
		}
		
		i = nexti[min];
		j = nextj[min];
		board[i][j] = m;
	}	
	
	return 1;
}










