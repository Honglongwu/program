#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLUE 'b'
#define WHITE 'w'
#define RED 'r'

#define swap(x, y) { char tmp; tmp = color[x]; color[x] = color[y]; color[y] = tmp;}

int main()
{
	char color[] = {'b', 'r', 'w', 'b', 'w', 'w','b', 'r', 'b', 'w', 'r', '\0'};
	
	int bflag = 0;
	int wflag = 0;
	int rflag = strlen(color) - 1;
	int i;
	
	for (i = 0; i <= rflag; ++i)
		printf("%c ", color[i]);
	printf("\n");
		
	while(wflag <= rflag)
	{
		if(color[wflag] == WHITE)
		{
			wflag ++;
		}else if (color[wflag] == BLUE)
		{
			swap(wflag, bflag);
			bflag ++;
			wflag ++;
		}else
		{
			while(wflag < rflag && color[rflag] == RED)
			{
				rflag --;
			}
			swap(wflag, rflag);
			rflag --;
		}
	}
	
	for(i = 0; i < strlen(color); ++ i)
	{
		printf("%c ", color[i]);
	}
	printf("\n");

	return 0;
}

