#include <stdio.h> 
int main()
{
    int i = 0, j = 0;
    for (i = 1000; i <= 2000; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))/*闰年： 能被400整除　或者　能被4整除但不能被100整除*/
        {
            printf("%d\t", i);
            if ((++j) == 10)//使每行显示十个数字
            {
                printf("\n");
                j = 0;
            }
        }
    }
    return 0;
}