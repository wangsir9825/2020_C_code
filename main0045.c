#include <stdio.h>
#include <assert.h>
char* my_strcpy(char* arr,const char* str)
{
	char* ret = arr;
	assert(arr != NULL);//断言
	assert(str != NULL);
	while ((*arr++ = *str++));
	return ret;
}
int main()
{
	char arr[40] = "hahaha";
	my_strcpy(arr, "heiheihei");
	printf("%s", arr);
	return 0;
}