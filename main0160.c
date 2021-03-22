#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int max, arr[4];
	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
	max = arr[0];
	int i = 1;
	for (i = 1; i < 4; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d", max);
	return 0;
}