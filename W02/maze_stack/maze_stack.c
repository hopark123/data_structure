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

int  DIRECTION_OFFSETS[4][2] ={
	{0, -1}, // 위
	{1, 0}, // 오른쪽
	{0, 1}, // 아래쪽
	{-1, 0}, // 왼쪽
};

bool ft_wall(int map[Y_size][X_size], int x, int y)
{
	if (map[y][x] == 1 || x > X_size || x < 0 || y > Y_size || y < 0)
		return FALSE;
	return TRUE;
}

static void	print_map(int map[Y_size][X_size])
{
	system("clear");
	for (int i = 0 ; i < Y_size; i++)
		{
			for (int j = 0; j < X_size; j++)
			{
				if (map[i][j] == 1)
					printf("[x]");
				else if (map[i][j] == 0)
					printf("[ ]");
				else
					printf("[\x1b[31mo\x1b[0m]");
			}
			printf("\n");
		}
	system("sleep 0.2");
}

int	maze_dfs(int map[Y_size][X_size], LinkedStack *pStack)
{
	LinkedStack	*res = createLinkedStack();

	int step = 0;
	while(!isLinkedStackEmpty(pStack))
	{
		StackNode *now;
		
		now = popLS(pStack);
		int x = now->data % X_size;
		int y = now->data / X_size;
		free(now);
		map[y][x] = -1;
		StackNode new;
		new.data = y * Y_size + x;
		pushLS(res, new);
		print_map(map);
		if (y == Y_size - 1 && x == X_size - 1)
		{
			StackNode *temp = res->pTopElement;
			while (temp->pLLink)
			{
				printf("(%d, %d) <-", temp->data % X_size, temp->data / Y_size);
				temp = temp->pLLink;
			}
			printf("\n");
			return (TRUE);
		}
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			int dy;
			int dx;
			dx = x + DIRECTION_OFFSETS[i][0];
			dy = y + DIRECTION_OFFSETS[i][1];
			if (ft_wall(map, dx, dy) && map[dy][dx] != -1)
			{
				StackNode new;
				new.data = dy * Y_size + dx;
				pushLS(pStack, new);
				flag ++;
			}
		}
		if (flag == 0)
		{
			while (step--)
				popLS(res);
		}
		else
			step++;
	}

	return (FALSE);
}

int main()
{
	LinkedStack	*pStack = createLinkedStack();
	StackNode	Node;

	Node.data = 0;
	pushLS(pStack, Node);
	maze_dfs(myMaze, pStack);
	deleteLinkedStack(pStack);
}