#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int w = 0;
	int h = 0;
	float BMI = 0.0f;
	while (scanf("%d%d", &w, &h) != EOF)
	{
		BMI = (float)w / (float)(h * h) * 10000.0f;
		if (BMI < 18.5f)
			printf("Underweight\n");
		else if (BMI >= 18.5f && BMI <= 23.9f)
			printf("Normal\n");
		else if (BMI > 23.9f && BMI <= 27.9f)
			printf("Overweight\n");
		else
			printf("Obese\n");
	}
/*
	int weight = 0, height = 0;
	float BMI = 0.f;
	//循环读入体重和身高
	while(scanf("%d %d", &weight, &height) != EOF) {
		//根据公式计算BMI
		BMI = weight / (height/100.f * height/100.f);
		//使用if else嵌套判断BMI所在的区间，输出即可
		if(BMI < 18.5f)
			printf("Underweight\n");
		else if(BMI >=18.5f && BMI <= 23.9f)
			printf("Normal\n");
		else if(BMI > 23.9f && BMI <= 27.9f)
			printf("Overweight\n");
		else
			printf("Obese\n");
	}
*/

	return 0;
}