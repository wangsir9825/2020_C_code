#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	float arr[100] = { 0.f };
	float max = 0.f;//最高分
	float min = 0.f;//最低分
	float average = 0.f;//平均分
	int i = 0;
	while (scanf("%d", &n) != EOF)
	{
		max = 0.f;
		min = 1000.f;//这里值得注意，找最小值时可以将其赋值为最大值，这样再找就比较方便
		average = 0.f;
		for (i = 0; i < n; i++)
		{
			scanf("%f", &arr[i]);
			if (arr[i] > max)//找最高分
				max = arr[i];
			if (arr[i] < min)//找最低分
				min = arr[i];
			average += arr[i];
		}
		average /= n;//求平均分
		printf("%.2f %.2f %.2f\n", max, min, average);
	}
	return 0;
}