#include <stdio.h>

int T, v1, v2, start, vertex, front, rear;
int map[30][30];
int visit[30];
int queue[30];

void bfs(int v)
{
	printf("%d ", v);
	visit[v] = 1;
	queue[rear++] = v;

	while (front < rear)
	{
		int temp = queue[front++];
		for (int i = 1; i <= vertex; i++)
		{
			if (1 == map[temp][i] && 0 == visit[i])
			{
				queue[rear++] = i;
				printf("%d ", i);
				visit[i] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				map[i][j] = 0;
			}
			visit[i] = queue[i] = 0;
		}
		front = rear = 0;
		scanf("%d %d", &vertex, &start);
		while (1)
		{
			scanf("%d %d", &v1, &v2);
			if (-1 == v1 && -1 == v2)
				break;
			map[v1][v2] = map[v2][v1] = 1;
		}
		printf("#%d ", tc);
		bfs(start);
		printf("\n");
	}
	return 0;
}