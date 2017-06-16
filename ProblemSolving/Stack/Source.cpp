#include <stdio.h>

int T, N, val, top;
int stack[101];

void push(int v)
{
	stack[++top] = val;
}

int pop()
{
	return stack[top--];
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		top = -1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &val);
			push(val);
		}
		printf("#%d ", tc);
		while (top > -1)
			printf("%d ", pop());
		printf("\n");
	}
	return 0;
}