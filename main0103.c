#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define	N 10
int main()
{
	int arr[N] = { 0 };
	int i = 0;
	int pos = 0;
	int neg = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > 0)
			pos++;
		if (arr[i] < 0)
			neg++;
	}
	printf("positive:%d\nnegative:%d\n", pos, neg);

	return 0;
}