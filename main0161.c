#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int M, C, E;
	scanf("%d %d %d", &M, &C, &E);
	int average = (M + C + E)/3;
	if(average < 60)
		printf("YES");
	else
		printf("NO");
	return 0;
}