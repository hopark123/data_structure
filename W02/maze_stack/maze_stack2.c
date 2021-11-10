#include "../LLStack/LLStack.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


#define X_size 8
#define Y_size 8

int myMaze[8][8] ={
	{0,  0,  1,  1,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  1},
	{1,  1,  1,  0,  1,  1,  1,  1},
	{1,  1,  1,  0,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  1},
	{1,  0,  1,  0,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  0},
	{1,  1,  1,  1,  1,  1,  1,  0}
};

int  DIRECTION_OFFSETS[4][2] =
{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

bool ft_wall(int map[Y_size][X_size], int x, int y)
{
	if (map[y][x] == -1 || x > X_size || x < 0 || y > Y_size || y < 0)
		return FALSE;
	return TRUE;
}

static void	print_map(int map[Y_size][X_size])
{
	// system("clear");
	for (int i = 0; i < Y_size; i++)
		{
			for (int j = 0; j < X_size; j++)
			{
				if (map[i][j] == -1)
					printf("[ x]");
				else if (map[i][j] == 0)
					printf("[  ]");
				else
					printf("[\x1b[31m%2d\x1b[0m]", map[i][j]);
					// printf("[\x1b[31mo\x1b[0m]");
			}
			printf("\n");
		}
	printf("\n");
	// system("sleep 0.2");
}

int	maze_dfs(int map[Y_size][X_size], LinkedStack *pStack)
{
	int	step = 0;

	while(!isLinkedStackEmpty(pStack))
	{
		StackNode *now;

		now = popLS(pStack);
		int x = now->data % X_size;
		int y = now->data / X_size;
		free(now);
		print_map(map);
		if (map[y][x] != 0)
			step = map[y][x];
		else
			step = 1;
		for (int i = 0; i < 4; i++)
		{
			int dy;
			int dx;
			dx = x + DIRECTION_OFFSETS[i][0];
			dy = y + DIRECTION_OFFSETS[i][1];
			if (ft_wall(map, dx, dy) && (map[dy][dx] > step + 1 || map[dy][dx] == 0))
			{
				StackNode new;
				new.data = dy * X_size + dx;
				map[dy][dx] = step + 1;
				pushLS(pStack, new);
			}
		}
	}
	return (map[Y_size - 1][X_size - 1]);
}

int main()
{
	LinkedStack	*pStack = createLinkedStack();
	LinkedStack	*root = createLinkedStack();
	StackNode	Node;
	int	maxfoot;

	Node.data = 0;
	pushLS(pStack, Node);
	for (int i = 0 ; i < Y_size; i++)
		{
			for (int j = 0; j < X_size; j++)
			{
				if (myMaze[i][j] == 1)
					myMaze[i][j] = -1;
			}
			printf("\n");
		}
	myMaze[0][0] = 1;
	maxfoot = maze_dfs(myMaze, pStack);
	Node.data = (Y_size - 1) * X_size + (X_size - 1);
	pushLS(root, Node);
	for (int i = maxfoot; i > 0; i--)
	{
		StackNode *Now = peekLS(root);
		int x = Now->data % X_size;
		int y = Now->data / X_size;
		for (int j = 0; j < 4; j++)
		{
			int dx = x + DIRECTION_OFFSETS[j][0];
			int dy = y + DIRECTION_OFFSETS[j][1];
			if (ft_wall(myMaze, dx, dy) && myMaze[dy][dx] == i - 1)
			{
				Node.data = dy * X_size + dx;
				pushLS(root, Node);
				break ;
			}
		}
	}
	while (!isLinkedStackEmpty(root))
	{
		StackNode *print = popLS(root);
		int x = print->data % X_size;
		int y = print->data / X_size;
		printf("(%d, %d) ->", x, y);
		free(print);
	}
	deleteLinkedStack(pStack);
	deleteLinkedStack(root);
}