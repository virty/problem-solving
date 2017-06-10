#include <stdio.h>

int T, vertex, edge, start, end, v1, v2, min;
int map[31][31];
int visit[31];

void dfs(int v, int depth)
{
	visit[v] = 1;
	if (v == end)
	{
		if (-1 == min || depth < min)
			min = depth;
		return;
	}
	for (int i = 1; i <= vertex; i++)
	{
		if (1 == map[v][i] && 0 == visit[i])
		{
			dfs(i, depth + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d %d %d", &vertex, &edge, &start, &end);
		for (int i = 1; i < vertex; i++)
		{
			for (int j = 1; j < vertex; j++)
				map[i][j] = 0;
			visit[i] = 0;
		}
		for (int i = 0; i < edge; i++)
		{
			scanf("%d %d", &v1, &v2);
			map[v1][v2] = 1;
		}
		min = -1;
		dfs(start, 0);
		printf("#%d %d\n", tc, min);
	}
	return 0;
}