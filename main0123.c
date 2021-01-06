#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int hour = 0;
	int min = 0;
	int alarm = 0;
	scanf("%d:%d %d", &hour, &min, &alarm);
	min += alarm ;
	hour = (hour + (min / 60)) % 24;
	min %= 60;
	printf("%02d:%02d", hour, min);
	return 0;
}