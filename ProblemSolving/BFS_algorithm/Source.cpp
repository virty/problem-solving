#include <stdio.h>

int T, head, rear, R, C;
int queue[50 * 50][3];
int map[52][52];

void enqueue(int x, int y, int d)
{
	queue[head][0] = x;
	queue[head][1] = y;
	queue[head][2] = d;
	head++;
}

void dequeue(int *x, int *y, int *d)
{
	*x = queue[rear][0];
	*y = queue[rear][1];
	*d = queue[rear][2];
	rear++;
}

int bfs()
{
	int x, y, d;
	enqueue(1, 1, 0);
	map[1][1] = 0;
	while (rear <= head)
	{
		dequeue(&x, &y, &d);
		if (x == R && y == C)
			return d;
		if (x + 1 <= R && map[x + 1][y])
		{
			enqueue(x + 1, y, d + 1);
			map[x + 1][y] = 0;
		}
		if (x - 1 > 0 && map[x - 1][y])
		{
			enqueue(x - 1, y, d + 1);
			map[x - 1][y] = 0;
		}
		if (y + 1 <= C && map[x][y + 1])
		{
			enqueue(x, y + 1, d + 1);
			map[x][y + 1] = 0;
		}
		if (y - 1 > 0 && map[x][y - 1])
		{
			enqueue(x, y - 1, d + 1);
			map[x][y - 1] = 0;
		}
	}
	return -1;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		head = rear = 0;
		scanf("%d %d", &R, &C);
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				scanf("%d", &map[i][j]);
		printf("#%d %d\n", tc, bfs());
	}
	return 0;
}