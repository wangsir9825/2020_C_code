#include "contact.h"
// 注意每个函数保证功能单一，不要弄的太复杂

/* 内部隐藏函数实现 */
//初始化通讯录
	void InitContact(Contact** ppc) //用一级指针行不行呢？
	{
		*ppc = (Contact*)malloc(sizeof(Contact)+DEFAULT_SZ*sizeof(PeoInfo)); 
							// 开辟的空间：空通讯录占用的空间和两个联系人占用的空间（DEFAULT_SZ*sizeof(PeoInfo)是柔性数组的大小）
		if (*ppc == NULL)
		{
			perror("malloc");
			return;
		}
		(*ppc)->sz = 0;
		(*ppc)->capacity = DEFAULT_SZ;
		
		memset((*ppc)->data, 0, (*ppc)->capacity*sizeof(PeoInfo));//通讯录的地址空间初始化为0
		//memset((*ppc)->data, 0, DEFAULT_SZ*sizeof(PeoInfo));
	}
	//查找一个人的信息
	int FindPeoByName(Contact* pc, char name[])
	{
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			if (strcmp(pc->data[i].name, name) == 0)
				return i;
		}
		return -1;//找不到
	}
/* 通讯录函数实现 */

//退出销毁通讯录0
	void DestoryContact(Contact** ppc)
	{
		free(*ppc);
		*ppc = NULL;
	}
//增加一个人的信息1
	void Addcontact(Contact** ppc)
	{
		if ((*ppc)->sz == (*ppc)->capacity)//如果内存不够则增容
		{
			Contact* ptr = (Contact*)realloc((*ppc), sizeof(Contact) +
				((*ppc)->capacity + 2) * sizeof(PeoInfo));//一次增加两个容量
			if (ptr == NULL)
			{
				return;
			}
			else
			{
				(*ppc) = ptr;
				(*ppc)->capacity += 2;
				printf("增容成功\n");
			}
		}
		printf("请输入名字:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].name);
		printf("请输入年龄:>");
		scanf("%d", &((*ppc)->data[(*ppc)->sz].age));
		printf("请输入性别:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].sex);
		printf("请输入电话:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].tele);
		printf("请输入地址:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].addr);
		//提示添加成功
		(*ppc)->sz++;
		printf("增加联系人成功\n");
	}

//删除一个人的信息2
	void DelContact(Contact* pc)
	{
		if (pc->sz == 0)
		{
			printf("通信录为空，不能删除\n");
		}
		else
		{
			char name[MAX_NAME] = { 0 };
			printf("请输入你要删除的人的名字:>");
			scanf("%s", name);
			//查找
			int pos = FindPeoByName(pc, name);
			//按名字删除
			if (-1 == pos)
			{
				printf("要删除的人不存在\n");
			}
			else
			{
				int j = 0;
				for (j = pos; j < pc->sz-1; j++)//sz-1是为了防止越界
				{
					pc->data[j] = pc->data[j + 1];
				}
				pc->sz--;
				printf("删除成功\n");
			}
		}
	}
//查找指定联系人信息3
	void SearchContact(Contact* pc) 
	{
		if (pc->sz == 0)
		{
			printf("通信录为空\n");
		}
		char name[MAX_NAME] = { 0 };
		printf("请输入你要查找的人的名字:>");
		scanf("%s", name);
		//查找
		int pos = FindPeoByName(pc, name);
		//按名字删除
		if (-1 == pos)
		{
			printf("要查找的人不存在\n");
		}
		else
		{
			printf("找到了：\n");
			printf("%20s\t%5s\t%5s\t%12s\t%15s\n",
				"name", "age", "sex", "tele", "addr");
			printf("%20s\t%5d\t%5s\t%12s\t%15s\n",
				pc->data[pos].name,
				pc->data[pos].age,
				pc->data[pos].sex,
				pc->data[pos].tele,
				pc->data[pos].addr);
		}
	}
//修改一个人的信息4
	void ModifyContact(Contact* pc)
	{
		if (pc->sz == 0)
		{
			printf("通信录为空\n");
		}
		char name[MAX_NAME] = { 0 };
		printf("请输入你要修改的人的名字:>");
		scanf("%s", name);
		//查找
		int pos = FindPeoByName(pc, name);
		//按名字删除
		if (-1 == pos)
		{
			printf("通讯录中没有%s\n", name);
		}
		else
		{
			printf("请输入修改后的名字:>");
			scanf("%s", pc->data[pos].name);
			printf("请输入修改后的年龄:>");
			scanf("%d", &(pc->data[pos].age));
			printf("请输入修改后的性别:>");
			scanf("%s", pc->data[pos].sex);
			printf("请输入修改后的电话:>");
			scanf("%s", pc->data[pos].tele);
			printf("请输入修改后的地址:>");
			scanf("%s", pc->data[pos].addr);
			//提示修改成功
			printf("修改成功\n");
		}
	}
//显示通讯录5
	void ShowContact(const Contact* pc)
	{
		int i = 0;
		//右对齐显示
		printf("%20s\t%5s\t%5s\t%12s\t%15s\n",
			"name", "age", "sex", "tele", "addr");
		//左对齐显示
		//printf("%-20s\t%-5s\t%-5s\t%-12s\t%-15s\n",
		//	"name", "age", "sex", "tele", "addr");
		for (i = 0; i < pc->sz; i++)
		{
			printf("%20s\t%5d\t%5s\t%12s\t%15s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
		}
	}
// 以名字排序所有联系人6
	// 参考代码：https://www.runoob.com/cprogramming/c-examples-lexicographical-order.html
	void SortContact(Contact* pc)
	{
		int i, j;
		char temp_name[MAX_NAME];
		int temp_age;
		char temp_sex[MAX_SEX];
		char temp_tele[MAX_TELE];
		char temp_addr[MAX_ADDR];
		for (i = 0; i < (pc->sz) - 1; ++i) {
			for (j = i + 1; j < pc->sz; ++j)
			{
				if (strcmp(pc->data[i].name, pc->data[j].name) > 0)
				{
					strcpy(temp_name, pc->data[i].name);
					strcpy(pc->data[i].name, pc->data[j].name);
					strcpy(pc->data[j].name, temp_name);

					temp_age = pc->data[i].age;
					pc->data[i].age = pc->data[j].age;
					pc->data[j].age = temp_age;

					strcpy(temp_sex, pc->data[i].sex);
					strcpy(pc->data[i].sex, pc->data[j].sex);
					strcpy(pc->data[j].sex, temp_sex);

					strcpy(temp_tele, pc->data[i].tele);
					strcpy(pc->data[i].tele, pc->data[j].tele);
					strcpy(pc->data[j].tele, temp_tele);

					strcpy(temp_addr, pc->data[i].addr);
					strcpy(pc->data[i].addr, pc->data[j].addr);
					strcpy(pc->data[j].addr, temp_addr);
				}
			}
		}
		printf("排序完成：\n");
	}
	// 清空所有联系人7
	void ClsContact(Contact* pc)
	{
		pc->sz = 0;
		printf("清空成功\n");
	}






