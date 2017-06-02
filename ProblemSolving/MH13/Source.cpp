#include <stdio.h>

#define OFFSET 1
#define EMPTY 0

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int t, m, n, x, y, cnt;

void process(char map[10][10], int x, int y, int dir);
void process1(char map[10][10], int x, int y, int dir);
void process2(char map[10][10], int x, int y, int dir);
void process3(char map[10][10], int x, int y, int dir);

// /
void process1(char map[10][10], int x, int y, int dir)
{
	if (dir == UP)
		process(map, x, y - 1, RIGHT);
	else if (dir == DOWN)
		process(map, x, y + 1, LEFT);
	else if (dir == LEFT)
		process(map, x - 1, y, DOWN);
	else
		process(map, x + 1, y, UP);
}

// "\"
void process2(char map[10][10], int x, int y, int dir)
{
	if (dir == UP)
		process(map, x, y + 1, LEFT);
	else if (dir == DOWN)
		process(map, x, y - 1, RIGHT);
	else if (dir == LEFT)
		process(map, x + 1, y, UP);
	else
		process(map, x - 1, y, DOWN);
}

// .
void process3(char map[10][10], int x, int y, int dir)
{
	if (dir == UP)
		process(map, x + 1, y, UP);
	else if (dir == DOWN)
		process(map, x - 1, y, DOWN);
	else if (dir == LEFT)
		process(map, x, y + 1, LEFT);
	else
		process(map, x, y - 1, RIGHT);
}

void process(char map[10][10], int x, int y, int dir)
{
	if (map[x][y] == EMPTY)
		return;
	else if ('Y' == map[x][y])
	{
		int temp = 1;
		for (int i = 1; i < m + 1; i++)
			for (int j = 1; j < n + 1; j++)
				if (map[i][j] == '?')
					temp *= 3;
		cnt += temp;
	}
	else
	{
		if (map[x][y] == '/')
			process1(map, x, y, dir);
		else if (map[x][y] == '\\')
			process2(map, x, y, dir);
		else if (map[x][y] == '.')
			process3(map, x, y, dir);
		else if (map[x][y] == '?')
		{
			map[x][y] = '/';
			process1(map, x, y, dir);

			map[x][y] = '\\';
			process2(map, x, y, dir);

			map[x][y] = '.';
			process3(map, x, y, dir);

			map[x][y] = '?';
		}
	}
}

int main()
{
	scanf("%d", &t);

	while (t--)
	{
		cnt = 0;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		char map[10][10] = { 0, };

		for (int i = 0; i < m; i++)
		{
			scanf("%s", map[i + OFFSET] + OFFSET);
		}

		if (y <= n)
			map[0][y] = 'Y';
		else if (y <= m + n)
			map[y - n][0] = 'Y';
		else if (y <= 2 * m + n)
			map[y - m - n][n + 1] = 'Y';
		else
			map[m + 1][y - 2 * m - n] = 'Y';

		if (x <= n)
			process(map, 1, x, UP);
		else if (x <= m + n)
			process(map, x - n, 1, LEFT);
		else if (x <= 2 * m + n)
			process(map, x - m - n, n, RIGHT);
		else
			process(map, m, x - 2 * m - n, DOWN);

		printf("%d\n", cnt % 10007);
	}
	return 0;
}