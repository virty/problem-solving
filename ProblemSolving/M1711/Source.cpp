#include <stdio.h>

int main()
{
	int T, N;
	int x1, y1, x2, y2, dx, dy, c1, c2, c3;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		c1 = c2 = c3 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &dx, &dy);
			if (dx < x1 || x2 < dx || dy < y1 || y2 < dy)
				c3++;
			else if (x1 < dx && dx < x2 && y1 < dy && dy < y2)
				c1++;
			else
				c2++;
		}
		printf("#%d %d %d %d\n", tc, c1, c2, c3);
	}
	return 0;
}