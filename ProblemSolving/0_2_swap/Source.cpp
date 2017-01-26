#include <stdio.h>

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main()
{
	int a = 10;
	int b = 5;
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	swap_arr(arr, 2, 5);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}