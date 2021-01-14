#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* cp = str1;
	while (*cp)
	{
		const char* sr1 = cp;
		const char* sr2 = str2;
		while (*sr1 && *sr2 && *sr1 == *sr2)
		{
			sr1++;
			sr2++;
		}
		if (*sr2 == '\0')
			return cp;
		cp++;
	}
	return NULL;
}
int main()
{
	char* p1 = "I am so hansome";
	char* p2 = "am";
	char* pn = my_strstr(p1, p2);
	if (pn == NULL)
	{
		printf("字符串p2“不是”字符串p1的一部分\n");
	}
	else
	{
		printf("字符串p2“是”字符串p1的一部分\n");
	}
	system("pause");
	return 0;
}