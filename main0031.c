#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	m = m ^ n;
	n = 0;
	while (m)
	{
		if (m % 2 == 1)
		{
			n++;
		}
		m /= 2;
	}
	printf("%d", n);
	return 0;
}