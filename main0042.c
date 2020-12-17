#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define DZ1 0.7
#define DZ2 0.8
double mon_func(double* money,double DZ, int flag)
{
	if (flag)
	{
		if ((*money * DZ - 50.0) < 0)
			*money = 0.00;
		else
			*money = *money * DZ - 50.0;
	}
	else
		*money = *money * DZ;
	return *money;
}
int main()
{
	double money = 0;
	int month = 0;
	int day = 0;
	int flag = 0;
	scanf("%lf%d%d%d", &money, &month, &day, &flag);
	//是否有折扣
	//bool discount = flag == 1 ? true : false;
	if (month == 11 && day == 11)
	{
		mon_func(&money, DZ1, flag);
	}
	else if(month == 12 && day == 12)
	{
		mon_func(&money, DZ2, flag);
	}
	else
	{
		mon_func(&money, 1, flag);
	}
	printf("%.2lf", money);
	return 0;
}