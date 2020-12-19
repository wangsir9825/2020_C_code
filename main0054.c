#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int Chinese = 0;
	int math = 0;
	int English = 0;
	int highest = 0;
	while (scanf("%d%d%d", &Chinese, &math, &English) != EOF)
	{
		highest = Chinese > math ? Chinese : math;
		highest = highest > English ? highest : English;
		printf("%d\n", highest);
	}

	return 0;
}