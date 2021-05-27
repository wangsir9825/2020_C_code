#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h> 

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
		PeoInfo data[MAX];//存储空间
		int sz;//记录当前通讯录中元素的个数

	}Contact;
//函数声明

//初始化通讯录
	void InitContact(Contact* pc);
//添加联系人信息1
	void Addcontact(Contact* pc);
//显示所有联系人信息5
	void ShowContact(const Contact* pc);//常指针参数操作更安全
//删除指定联系人信息2
	void DelContact(Contact* pc);
//查找指定联系人信息3
	void SearchContact(Contact* pc);
//修改指定联系人信息4
	void ModifyContact(Contact* pc);
// 以名字排序所有联系人6
	void SortContact(Contact* pc);
// 清空所有联系人7
	void ClsContact(Contact* pc);