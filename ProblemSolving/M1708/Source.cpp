#include <stdio.h>
int block[101];

int main()
{
	int T, N;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int diff = 0, maxUp = 0, maxDown = 0;
		scanf("%d", &N);
		scanf("%d", &block[0]);
		for (int i = 1; i < N; i++)
		{
			scanf("%d", &block[i]);
			diff = block[i - 1] - block[i];
			if (diff < 0)
			{
				diff = -diff;
				if (diff > maxUp)
					maxUp = diff;
			}
			else
			{
				if (diff > maxDown)
					maxDown = diff;
			}
		}
		printf("#%d %d %d\n", tc, maxUp, maxDown);
	}
	return 0;
}