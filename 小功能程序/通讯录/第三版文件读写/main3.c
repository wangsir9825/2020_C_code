
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//
#if 1
/**************
程序功能：实现通讯录，用一个指针维护通讯录，该指针指向一个通讯录结构体，结构体内有一个柔性数组用于保存联系人信息
时间：2021年5月27日10:30:12

通讯录空间可以逐渐增加

每个人的信息：名字+电话+年龄+性别+地址
增加，删除，修改，查找，排序

***************/


#include "contact.h"
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT,//6
	CLS,//7
	SAVE //8
};
void menu()
{
	printf("*********************************\n");
	printf("*** 1.add           2.del  ******\n");
	printf("*** 3.search        4.modify ****\n");
	printf("*** 5.show          6.sort  *****\n");
	printf("*** 0.exit          7.cls  ******\n");
	printf("*** 8.save                 ******\n");
	printf("*********************************\n");
}
void test()
{
	int input = 0;
	//创建通讯录
	Contact* pc;//维护通讯录的指针(未初始化的野指针)

	InitContact(&pc);//初始化通讯录（之所以传入pc的地址，是因为我们想改变这个指针的指向）
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD: // 1
			Addcontact(&pc);
			break;
		case DEL: // 2
			DelContact(pc);
			break;
		case SEARCH: // 3
			SearchContact(pc);
			break;
		case MODIFY: // 4
			ModifyContact(pc);
			break;
		case SHOW: // 5
			ShowContact(pc);//为保证效率，所以传递地址参数
			break;
		case SORT://6
			SortContact(pc);
			ShowContact(pc);
			break;
		case CLS://7
			SaveContact(pc);
			ClsContact(pc);
			break;
		case SAVE://8
			SaveContact(pc);
			break;
		case EXIT: // 0
			DestoryContact(&pc);//销毁通讯录（让pc指向空指针）
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

}
int main()
{
	test();
	return 0;
}
#endif



//程序模板
//
#if 0
/**************
程序功能：
时间：

***************/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{

	return 0;
}
#endif



