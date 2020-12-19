#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	double a, b;
	char ch;
	while (scanf("%lf%c%lf", &a, &ch, &b) != EOF)
	{
		if (ch == '+')
		{
			printf("%.4lf%c%.4lf=%.4lf\n", a, ch, b, a + b);
		}
		else if (ch == '-')
		{
			printf("%.4lf%c%.4lf=%.4lf\n", a, ch, b, a - b);
		}
		else if (ch == '*')
		{
			printf("%.4f%c%.4f=%.4f\n", a, ch, b, a * b);
		}
		else if (ch == '/')
		{
			if (b == 0.0)
				printf("Wrong!Division by zero!\n");
			else
				printf("%.4lf%c%.4lf=%.4lf\n", a, ch, b, a / b);
		}
		else
		{
			printf("Invalid operation!\n");
		}

	}
	return 0;
/*
	double a = 0.0, b = 0.0;
	char op = 0;
	//题解2思路和上述一直，这里没有使用if else嵌套而是使用了switch运算符
	//让代码看起来更加工整
	while(scanf("%lf%c%lf", &a, &op, &b) != EOF) {
		switch (op) {
			case '+': printf("%.4lf+%.4lf=%.4lf\n", a, b, a+b); break;
			case '-': printf("%.4lf-%.4lf=%.4lf\n", a, b, a-b); break;
			case '*': printf("%.4lf*%.4lf=%.4lf\n", a, b, a*b); break;
			case '/':
				if(b != 0.0)
					printf("%.4lf/%.4lf=%.4lf\n", a, b, a/b);
				else
					printf("Wrong!Division by zero!\n");
				break;
			default: printf("Invalid operation!\n"); break;
		}
	}
*/

}