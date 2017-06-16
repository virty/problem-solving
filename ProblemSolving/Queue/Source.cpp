#include <stdio.h>

int T, N, val, head, rear;
int queue[101];

int isEmpty()
{
	return rear >= head ? 1 : 0;
}

void enqueue(int val)
{
	queue[head++] = val;
}

int dequeue()
{
	return queue[rear++];
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		head = rear = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &val);
			enqueue(val);
		}
		printf("#%d ", tc);
		while (!isEmpty())
			printf("%d ", dequeue());
		printf("\n");
	}
	return 0;
}