#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 10
int main()
{
	int i = 0;
	int grd_arr[N] = { 0 };
	for (i = 0; i < N; i++)
	{
		scanf("%d", &grd_arr[i]);
		printf("%d ", grd_arr[i]);
	}
	//for (i = 0; i < N; i++)
	//	printf("%d", grd_arr[i]);
	return 0;
}