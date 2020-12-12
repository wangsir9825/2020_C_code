int main()
{
	int n;
	while (scanf("%d", &n) != EOF)	//EOF，这是在stdio.h里面定义的常量（通常值为-1），表示输入流已
									//经结束。在Windows下，用户按下CTRL+Z（会看到一个^Z字符）再按下回车（可能需要重复2次），就表示输入结束；
	{
		getchar();//吸收回车
		printf("%d\n", (1 << n));
	}
	return 0;
}