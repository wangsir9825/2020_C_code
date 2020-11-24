#include <stdio.h>
int main()
{
	int i = 0;
	int j = 1;
	float sum = 0;
	//float num;
	for (i = 1; i <= 100; i++)
	{
		//num = j * i;
		//sum = sum + 1 / num;
		sum = sum + (float)j/i;
		j = j * (-1);
	}
	printf("%f", sum);
	return 0;
}