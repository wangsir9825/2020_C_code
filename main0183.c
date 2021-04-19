#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    printf("argc:%d\n",argc);//输出命令行参数的个数
    int i = 0;
    for(i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]); //输出命令行参数值
    }
    while(1)
    {
        printf("hello 86\n");
        sleep(1);
    }
    return 0; 
}


