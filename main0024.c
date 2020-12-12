#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char a;
	while ((a= getchar()) != EOF)//getchar()遇到键盘输入ctrl+z 时，能获得EOF，则终止循环					
	{						//EOF是end of file的缩写，是定义在头文件stdio.h的一个宏，
							//它的值为-1。（#define EOF (-1)）
							
		getchar(); //循环多次读入，利用gethar消去读入的换行符
		if (a == '\n')
			printf("\n");
		else
			printf("%c\n", a + 32);
	}
	return 0;
}