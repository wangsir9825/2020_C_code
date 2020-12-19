#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int IQ = 0;
	while (scanf("%d", &IQ) != EOF)
	{
		if (IQ >= 140)
		{
			printf("Genius\n");
		} 
	}  
	return 0;
}
