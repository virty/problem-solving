#include <stdio.h>
#define QUEUE_SIZE 8

int queue[QUEUE_SIZE];
int head = 0;
int tail = -1;
int queue_size = 0;

void enqueue(int n)
{
	if (queue_size == QUEUE_SIZE)
	{
		printf("queue full!\n");
		return;
	}
	//tail++;
	tail = (tail + 1) % QUEUE_SIZE;
	queue_size++;
	queue[tail] = n;
}

int dequeue()
{
	int r;
	if (queue_size == 0)
	{
		printf("queue empty!\n");
		return 0;
	}
	r = queue[head];
	queue_size--;
	//head++;
	head = (head + 1) % QUEUE_SIZE;
	return r;
}

int main()
{
	int number;
	do {
		printf("input number : ");
		scanf("%d", &number);
		if (number > 0)
		{
			enqueue(number);
		}
		else if (number == 0)
		{
			int r;
			r = dequeue();
			printf("[%d]\n", r);
		}
	} while (number >= 0);
	return 0;
}