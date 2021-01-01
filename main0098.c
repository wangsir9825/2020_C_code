#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 5
int main()
{
	int A, B, C, D, E;
	for (A = 1; A <= N; A++)
	{
		for (B = 1; B <= N; B++)
		{
			for (C = 1; C <= N; C++)
			{
				for (D = 1; D <= N; D++)
				{
					for (E = 1; E <= N; E++)
					{
						if (A * B * C * D * E == 120 && A + B + C + D + E == 15)
							if ((((B == 2) + (A == 3))
								+ ((E == 4))
								+ ((C == 1) + (D == 2))
								+ ((C == 5) + (D == 3))
								+ ((A == 1)) == 5))
								printf("A = %d B = %d C = %d D = %d E = %d\n",A,B,C,D,E);
					}
				}
			}
		}
	}
	return 0;
}