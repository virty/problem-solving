#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#include <stdio.h>

int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int max_arr(int arr[], int length)
{
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int max_arr_rec(int arr[], int length)
{
	if (length == 1)
		return arr[0];
	return max(arr[length - 1], max_arr_rec(arr, length - 1));
}

int main()
{
	printf("min = %d\n", min(3, 5));
	printf("max = %d\n", max(3, 5));

	printf("MIN = %d\n", MIN(3, 5));
	printf("MAX = %d\n", MAX(3, 5));

	int test_arr[] = { 45,89,45,86,54,453,54,8796,552 };
	printf("max_arr = %d\n", max_arr(test_arr, 9));
	printf("max_arr_rec = %d\n", max_arr_rec(test_arr, 9));
	return 0;
}