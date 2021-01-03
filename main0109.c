#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int N = 0;
	int arr[1000] = { 0 };
	int i = 0;
	int j = 0;
	int num = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < N; i++)
	{
		if (arr[i] != 0)
		{
			for (j = i + 1; j < N; j++)
			{
				if (arr[j] == arr[i])
					arr[j] = 0;
			}
			printf("%d ", arr[i]);
		}
	}
	return 0;
}