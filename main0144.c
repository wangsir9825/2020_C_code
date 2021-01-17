#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* my_strncpy(char* des, const char* src, size_t num)
{
	char* ret = des;
	assert(des != NULL);
	assert(src != NULL);
	while (num--)
	{
		if (*src == '\0')
		{
			*des++ = '\0';
		}
		else
		{
			*des++ = *src++;
		}
	}
	return ret;
}
int main()
{
	char des[20];//目标空间 = {'\0'}
	char src[] = { 'a','b','c','d','e','f','\0'};//源字符串 
	size_t num = 4;
	char* pdes = my_strncpy(des, src, num);
	des[num] = '\0';//复制完毕后，为保险起见，将最后一个字符置为NULL
	printf("%s\n", pdes);
	system("pause");
	return 0;
}