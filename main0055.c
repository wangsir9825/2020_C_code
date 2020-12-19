#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char ch = '0';
	while (scanf("%c", &ch) != EOF)
	{
/*		
		if (ch == '\n')//忽略换行符
			continue;
		统一将字符转换成大写，方便后续判断
		if (ch >= 'a' && ch <= 'z')
			ch -= 32;
		//判断是否为元音字母
		if (ch == 'A' || ch == 'E' || ch == 'I'
			|| ch == 'O' || ch == 'U')
		{
			printf("Vowel\n");
		}
		else
		{
			printf("Consonant\n");
		}
*/
		if (ch == '\n')
			getchar();
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			printf("Vowel\n");
		else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			printf("Vowel\n");
		else
			printf("Consonant\n");

	}
	return 0;
}