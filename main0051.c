#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int grade = 0;
	while (scanf("%d", &grade) != EOF)
	{
		if (grade >= 90 && grade <= 100)
		{
			printf("Perfect\n");
		}
	}

	return 0;
}
