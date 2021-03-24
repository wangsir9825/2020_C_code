#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int arr[100] = { 0 };
	int x = 0;
	int i = 0;
	int num = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);
	for (i = 0; i < n; ++i)
	{
		if (x == arr[i])
			++num;
	}
	printf("%d", num);
	return 0;
}