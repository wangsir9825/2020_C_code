#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define cons 60
int main()
{
	int seconds = 0;
	int min = 0;
	int hour = 0;
	scanf("%d", &seconds);
	min = seconds / cons;
	seconds = seconds % cons;
	hour = min / cons;
	min = min % cons;
	printf("%d %d %d", hour, min, seconds);
	return 0;
}