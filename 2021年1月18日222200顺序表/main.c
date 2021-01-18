#define  _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SeqList mylist;//定义顺序表
	SeqListInit(&mylist);//顺序表初始化，确定其大小

	ElemType item, key;

	size_t pos;

	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("*************当前顺序表的元素有：***********\n");
		SeqListShow(&mylist);//显示顺序表
		printf("******元素个数：%d *******顺序表容量：%d *****\n", SeqListLength(&mylist), SeqListCapacity(&mylist));
		printf("********************************************\n");
		printf("* [1] push_back        [2] push_front      *\n");//尾插和头插
		printf("* [3] show_list        [0] quit_system     *\n");//显示和退出
		printf("* [4] pop_back         [5] pop_front       *\n");//尾删和头删
		printf("* [6] length           [7] capacity        *\n");//查看顺序表长度和容量
		printf("* [8] insert_val       [9] insert_pos      *\n");//按值插入、按位置插入
		printf("* [10] delete_val      [11] delete_pos     *\n");//按值删除、按位置删除
		printf("* [12] find            [13] sort           *\n");//查找元素和冒泡排序
		printf("* [14] reverse         [15] remove_all     *\n");//位置翻转和移除所有某一元素
		printf("* [16] clear           [*17] destroy       *\n");//清除和摧毁
		printf("* [18] find_binary                         *\n");//二分查找（必须先进行排序）
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1://尾插
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SeqListPushBack(&mylist, item);
			break;
		case 2://头插
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SeqListPushFront(&mylist, item);
			break;
		case 3://显示
			SeqListShow(&mylist);//显示顺序表
			break;
		case 4://尾删
			SeqListPopBack(&mylist);
			break;
		case 5://头删
			SeqListPopFront(&mylist);
			break;
		case 6://查看长度
			printf("表长为:>%d\n", SeqListLength(&mylist));//查看长度
			break;
		case 7://查看容量
			printf("表的容量为:>%d\n", SeqListCapacity(&mylist));//查看容量
			break;
		case 8://按值插入，插入之前要保证数据有序
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 9://按位置插入
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;

		case 10://按值删除
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListDeleteByVal(&mylist, key);
			break;
		case 11://按位置删除
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListDeleteByPos(&mylist, pos);
			break;
		case 12://查找元素
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d在下标为%d的位置.\n", key, pos);
			break;
		case 13://冒泡排序
			SeqListSort(&mylist);
			break;
		case 14://位置翻转
			SeqListReverse(&mylist);
			break;
		case 15://移除所有某一元素
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			break;
		case 16://清除 （清除所有元素）
			SeqListClear(&mylist);
			break;
		case 18://二分查找（必须先进行排序）
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFindByBinary(&mylist, key);
			if (pos == -1)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d在下标为%d的位置.\n", key, pos);
			break;
		}
		system("pause");//暂停一下
		//system("cls");//清屏
	}

	SeqListDestroy(&mylist);//在程序结束前，摧毁顺序表，即释放内存

	return 0;
}