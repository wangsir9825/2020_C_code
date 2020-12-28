#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[20] = { '0' };
	char arr2[20] = { '0' };
	while (scanf("%s %s", arr1, arr2) != EOF)
	{
		if ((strcmp("admin", arr1) == 0) && (strcmp("admin", arr2) == 0))//判断用户名和密码是否正确
			printf("Login Success!\n");
		else
			printf("Login Fail!\n");
	}
	return 0;
}