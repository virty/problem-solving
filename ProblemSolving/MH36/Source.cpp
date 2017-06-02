#include <stdio.h>

int T, N, M;
char culture[100][10001];

int getEfromW(int index)
{
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (culture[j][i] == 'E')
				count++;
		}
	}
	return count;
}

int getWfromE(int index)
{
	int count = 0;
	for (int i = index; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (culture[j][i] == 'W')
				count++;
		}
	}
	return count;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++)
		{
			scanf("%s", culture[i]);
		}

		for (int i = N; i >= 0; i--)
		{
			int E_W = getEfromW(i);
			int W_E = getWfromE(i);

			printf("%d %d\n", E_W, W_E);
		}
	}
	return 0;
}