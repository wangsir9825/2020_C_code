
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h> //memset
#include <stdlib.h> //malloc、

#define DEFAULT_SZ 2 //默认通讯录大小

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 20
#define MAX_TELE 12
//
//每个人的信息：名字+电话+年龄+性别+地址
//增加，删除，修改，查找，排序
//
//类型声明
//个人信息类型
	typedef struct PeoInfo
	{
		char name[MAX_NAME];
		int age;
		char sex[MAX_SEX];
		char tele[MAX_TELE];
		char addr[MAX_ADDR];
	}PeoInfo;
	//定义通讯录类型
	typedef struct Contact
	{
		//PeoInfo data[MAX];//存储空间
		int sz;//记录当前通讯录中元素的个数
		int capacity;//记录通讯录当前的最大容量
		PeoInfo data[]; //存储联系人信息的空间（柔性数组）
	}Contact;
//函数声明

// 初始化通讯录
	void InitContact(Contact** pc); 
// 退出销毁通讯录0
	void DestoryContact(Contact** pc);
// 增加一个人的信息1
	void Addcontact(Contact** pc);
// 删除一个人的信息2
	void DelContact(Contact* pc);
// 查找指定联系人信息3
	void SearchContact(Contact* pc);
// 修改指定联系人信息4
	void ModifyContact(Contact* pc);
// 显示通讯录5
	void ShowContact(const Contact* pc);//常指针参数操作更安全
// 以名字排序所有联系人6
	void SortContact(Contact* pc);
// 清空所有联系人7
	void ClsContact(Contact* pc);
// 保存通讯录信息到文件8
	void SaveContact(Contact* pc);
// 把文件中的联系人信息加载到通讯录中
	void LoadContact(Contact** pc);
// 增容
	void ChecCapcity(Contact** pc);





