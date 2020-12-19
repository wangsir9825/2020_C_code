#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	float deta = 0.f;
	float x1 = 0.f;
	float x2 = 0.f;
	while (scanf("%f%f%f", &a, &b, &c) != EOF)
	{
		if (a == 0.f)
			printf("Not quadratic equation\n");
		else
		{
			deta = b * b - 4.f * a * c;
			if (deta < 0)
			{
				x1= -b  / (2.f * a);//x1充当实部
				x2= sqrt(-deta) / (2.f * a);//x1充当虚部
				printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", x1, x2, x1, x2);
			}
			else
			{
				deta = sqrt(deta);
				x1 = (-b + deta) / (2.f * a);
				x2 = (-b - deta) / (2.f * a);
				if (deta == 0)
					printf("x1=x2=%.2f\n", x1);
				else
				{
					if (x1 > x2)
					{
						float xx=0.f;
						xx = x1;
						x1 = x2;
						x2 = xx;
					}
					printf("x1=%.2f;x2=%.2f\n", x1, x2);
				}			
			}
		}
	}
	return 0;
}