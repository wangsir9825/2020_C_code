#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define cons 31560000
int main()
{
	long long age = 0;
	scanf("%lld", &age);
	printf("%lld", age * cons);
	return 0;
}