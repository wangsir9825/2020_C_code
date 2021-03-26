#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[10][10], i, j, n, m, l;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	m = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (a[i][j] != 0) {
				m = 1;
			}
		}
	}
	if (m == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	printf("\n");
	return 0;
}