#include <stdio.h>
#include <stdlib.h>

void visit(int, int);

int maze[9][9] = {{2, 2, 2, 2, 2, 2, 2, 2, 2},{2, 0, 0, 0, 0, 0, 0, 0, 2}, {2, 0, 2, 2, 0, 2, 2, 0, 2}, {2, 0, 2, 0, 0, 2, 0, 0, 2}, {2, 0, 2, 0, 2, 0, 2, 0, 2}, {2, 0, 0, 0, 0, 0, 2, 0, 2}, {2, 2, 0, 2, 2, 0, 2, 2, 2}, {2, 0, 0, 0, 0, 0, 0, 0, 2},{2, 2, 2, 2, 2, 2, 2, 2, 2}};

int startI = 1;
int startJ = 1;
int endI = 7;
int endJ = 7;


int main(void)
{
	int i, j;
	printf("display the maze:\n");
	for(i = 0; i < 9; ++ i)
	{
		for(j = 0; j < 9; ++ j)
		{
			if(maze[i][j] == 2)
			{
				printf("I");
			}else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	visit(startI, startJ);
			
	return 0;
}

void visit(int i, int j)
{
	maze[i][j] = 1;
	
	int m, n;
	if(i == endI && j == endJ)
	{
		printf("display the full path:\n");
		for(m = 0; m < 9; ++ m)
		{
			for(n = 0; n < 9; n ++)
			{
				if(maze[m][n] == 2){printf("I ");}
				else if(maze[m][n] == 1){printf("> ");}
				else{printf(" ");}
			}
			printf("\n");
		}
	}
		
	if(maze[i][j + 1] == 0){visit(i, j + 1);}
	if(maze[i][j - 1] == 0){visit(i, j - 1);}
	if(maze[i - 1][j] == 0){visit(i - 1, j);}
	if(maze[i + 1][j] == 0){visit(i + 1, j);}
	
	maze[i][j] = 0;
}	

