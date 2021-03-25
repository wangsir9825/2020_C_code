#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	int arr[1001] = { 0 };
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &m);
		arr[m] = m;
	}
	for (i = 0; i <= 1000; ++i)
	{
		if (arr[i] != 0)
			printf("%d ", arr[i]);
	}
	return 0;
}