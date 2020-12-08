#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	long birthday;
	scanf("%ld", &birthday);
	int year = birthday / 10000;
	int month = (birthday % 10000) / 100;
	int date = birthday % 100;
	printf("year=%0004d\nmonth=%02d\ndate=%02d", year, month, date);
	return 0;
}