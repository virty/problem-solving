#include <stdio.h>

char culture[100][10001];

int main()
{
	int T, N, M;
	scanf("%d", &T);
	for (int tc = 1; tc <= 5; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++)
		{
			scanf("%s", culture[i]);
		}
	}
	return 0;
}