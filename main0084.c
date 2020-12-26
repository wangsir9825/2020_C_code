#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[7] = { 0 };
	int i = 0;
	int max = 0, min = 0;
	
	scanf("%d%d%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]);
	min = arr[0];
	for (i = 0; i < 7; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	for (i = 0; i < 7; i++)
	{
		if (arr[i] == max)
			arr[i] = 0;
		if (arr[i] == min)
			arr[i] = 0;
	}
	printf("%.2f", (float)(arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6]) / 5.f);
	return 0;
}