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
//ÿ���˵���Ϣ������+�绰+����+�Ա�+��ַ
//���ӣ�ɾ�����޸ģ����ң�����
//
//��������
	//������Ϣ����
	typedef struct PeoInfo
	{
		char name[MAX_NAME];
		int age;
		char sex[MAX_SEX];
		char tele[MAX_TELE];
		char addr[MAX_ADDR];
	}PeoInfo;
	//����ͨѶ¼����
	typedef struct Contact
	{
		PeoInfo data[MAX];//�洢�ռ�
		int sz;//��¼��ǰͨѶ¼��Ԫ�صĸ���

	}Contact;
//��������

//��ʼ��ͨѶ¼
	void InitContact(Contact* pc);
//�����ϵ����Ϣ1
	void Addcontact(Contact* pc);
//��ʾ������ϵ����Ϣ5
	void ShowContact(const Contact* pc);//��ָ�������������ȫ
//ɾ��ָ����ϵ����Ϣ2
	void DelContact(Contact* pc);
//����ָ����ϵ����Ϣ3
	void SearchContact(Contact* pc);
//�޸�ָ����ϵ����Ϣ4
	void ModifyContact(Contact* pc);
// ����������������ϵ��6
	void SortContact(Contact* pc);
// ���������ϵ��7
	void ClsContact(Contact* pc);