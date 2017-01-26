#include <stdio.h>

void right_rotate(int arr[], int s, int t)
{
	int last = arr[t];
	for (int i = t; i > s; i--)
		arr[i] = arr[i - 1];
	arr[s] = last;
}

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	right_rotate(arr, 2, 7);

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}