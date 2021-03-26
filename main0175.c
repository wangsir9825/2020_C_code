#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, m, a[110], count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) if (a[i] == m) count++;
	printf("%d\n", n - count);
	for (int i = 0; i < n; i++) {
		if (a[i] != m) printf("%d ", a[i]);
	}
	return 0;
}