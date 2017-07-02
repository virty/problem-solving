#include <stdio.h>

int T, V, E, Q, v1, v2, q1;
int edge[100][100];

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d %d", &V, &E, &Q);
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				edge[i][j] = 0;
		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &v1, &v2);
			edge[v1][v2] = edge[v2][v1] = 1;
		}
		printf("#%d\n", tc);
		for (int i = 0; i < Q; i++)
		{
			scanf("%d", &q1);
			for (int i = 0; i < V; i++)
				if (1 == edge[q1][i])
					printf("%d ", i);
			printf("\n");
		}
	}
	return 0;
}