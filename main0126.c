#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	long long int n = 0;
	int arr[10] = { 0 };
	int i = 0;
	scanf("%lld", &n);
	while (n)
	{
		if ((n % 10)%2 == 1)
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 0;
		}
		i++;
		n /= 10;
	}
	int flag = 0;
	for (i = 9; i >= 0; i--)
	{
		if (arr[i] == 1 || flag == 1)
		{
			flag = 1;
			printf("%d", arr[i]);
		}
	}
	if (flag == 0)
	{
		printf("0");
	}
	return 0;
}