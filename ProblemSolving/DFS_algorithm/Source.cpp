#include <stdio.h>

#define MAX_VERTEX 30

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int vertex;
int edge;
int maxEdge;
int start;
int end;

void depthFirstSearch(int v, int depth)
{
	int i;
	if (v == end)
	{
		if (maxEdge < 0 || depth < maxEdge)
		{
			maxEdge = depth;
		}
		return;
	}

	visit[v] = 1;
	for (i = 1; i <= vertex; i++)
	{
		if (map[v][i] == 1 && !visit[i])
		{
			depthFirstSearch(i, depth + 1);
			visit[i] = 0;
		}
	}
}


int main(void)
{
	int T;
	int test_case;
	int i;
	int v1;
	int v2;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d %d %d", &vertex, &edge, &start, &end);

		for (i = 0; i < edge; i++)
		{
			scanf("%d %d", &v1, &v2);
			map[v1][v2] = 1;
		}

		maxEdge = -1;
		depthFirstSearch(start, 0);
		printf("#%d %d\n", test_case, maxEdge);
	}
	return 0;
}