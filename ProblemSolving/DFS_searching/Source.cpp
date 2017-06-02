#include <stdio.h>

int T, v1, v2, vertex, start;
int map[31][31];
int visit[31];

void dfs_search(int v)
{
	printf("%d ", v);
	visit[v] = 1;
	for (int i = 1; i <= vertex; i++)
		if (1 == map[v][i] && 0 == visit[i])
			dfs_search(i);
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &vertex, &start);
		for (int i = 1; i <= vertex; i++)
		{
			visit[i] = 0;
			for (int j = 1; j <= vertex; j++)
				map[i][j] = 0;
		}
		while (1)
		{
			scanf("%d %d", &v1, &v2);
			if (-1 == v1 && -1 == v2)
				break;
			map[v1][v2] = map[v2][v1] = 1;
		}
		printf("#%d ", tc);
		dfs_search(start);
		printf("\n");
	}
	return 0;
}