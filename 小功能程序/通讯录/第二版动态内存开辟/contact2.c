#include "contact.h"
// ע��ÿ��������֤���ܵ�һ����ҪŪ��̫����

/* �ڲ����غ���ʵ�� */
//��ʼ��ͨѶ¼
	void InitContact(Contact** ppc) //��һ��ָ���в����أ�
	{
		*ppc = (Contact*)malloc(sizeof(Contact)+DEFAULT_SZ*sizeof(PeoInfo)); 
							// ���ٵĿռ䣺��ͨѶ¼ռ�õĿռ��������ϵ��ռ�õĿռ䣨DEFAULT_SZ*sizeof(PeoInfo)����������Ĵ�С��
		if (*ppc == NULL)
		{
			perror("malloc");
			return;
		}
		(*ppc)->sz = 0;
		(*ppc)->capacity = DEFAULT_SZ;
		
		memset((*ppc)->data, 0, (*ppc)->capacity*sizeof(PeoInfo));//ͨѶ¼�ĵ�ַ�ռ��ʼ��Ϊ0
		//memset((*ppc)->data, 0, DEFAULT_SZ*sizeof(PeoInfo));
	}
	//����һ���˵���Ϣ
	int FindPeoByName(Contact* pc, char name[])
	{
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			if (strcmp(pc->data[i].name, name) == 0)
				return i;
		}
		return -1;//�Ҳ���
	}
/* ͨѶ¼����ʵ�� */

//�˳�����ͨѶ¼0
	void DestoryContact(Contact** ppc)
	{
		free(*ppc);
		*ppc = NULL;
	}
//����һ���˵���Ϣ1
	void Addcontact(Contact** ppc)
	{
		if ((*ppc)->sz == (*ppc)->capacity)//����ڴ治��������
		{
			Contact* ptr = (Contact*)realloc((*ppc), sizeof(Contact) +
				((*ppc)->capacity + 2) * sizeof(PeoInfo));//һ��������������
			if (ptr == NULL)
			{
				return;
			}
			else
			{
				(*ppc) = ptr;
				(*ppc)->capacity += 2;
				printf("���ݳɹ�\n");
			}
		}
		printf("����������:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].name);
		printf("����������:>");
		scanf("%d", &((*ppc)->data[(*ppc)->sz].age));
		printf("�������Ա�:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].sex);
		printf("������绰:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].tele);
		printf("�������ַ:>");
		scanf("%s", (*ppc)->data[(*ppc)->sz].addr);
		//��ʾ��ӳɹ�
		(*ppc)->sz++;
		printf("������ϵ�˳ɹ�\n");
	}

//ɾ��һ���˵���Ϣ2
	void DelContact(Contact* pc)
	{
		if (pc->sz == 0)
		{
			printf("ͨ��¼Ϊ�գ�����ɾ��\n");
		}
		else
		{
			char name[MAX_NAME] = { 0 };
			printf("��������Ҫɾ�����˵�����:>");
			scanf("%s", name);
			//����
			int pos = FindPeoByName(pc, name);
			//������ɾ��
			if (-1 == pos)
			{
				printf("Ҫɾ�����˲�����\n");
			}
			else
			{
				int j = 0;
				for (j = pos; j < pc->sz-1; j++)//sz-1��Ϊ�˷�ֹԽ��
				{
					pc->data[j] = pc->data[j + 1];
				}
				pc->sz--;
				printf("ɾ���ɹ�\n");
			}
		}
	}
//����ָ����ϵ����Ϣ3
	void SearchContact(Contact* pc) 
	{
		if (pc->sz == 0)
		{
			printf("ͨ��¼Ϊ��\n");
		}
		char name[MAX_NAME] = { 0 };
		printf("��������Ҫ���ҵ��˵�����:>");
		scanf("%s", name);
		//����
		int pos = FindPeoByName(pc, name);
		//������ɾ��
		if (-1 == pos)
		{
			printf("Ҫ���ҵ��˲�����\n");
		}
		else
		{
			printf("�ҵ��ˣ�\n");
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
//�޸�һ���˵���Ϣ4
	void ModifyContact(Contact* pc)
	{
		if (pc->sz == 0)
		{
			printf("ͨ��¼Ϊ��\n");
		}
		char name[MAX_NAME] = { 0 };
		printf("��������Ҫ�޸ĵ��˵�����:>");
		scanf("%s", name);
		//����
		int pos = FindPeoByName(pc, name);
		//������ɾ��
		if (-1 == pos)
		{
			printf("ͨѶ¼��û��%s\n", name);
		}
		else
		{
			printf("�������޸ĺ������:>");
			scanf("%s", pc->data[pos].name);
			printf("�������޸ĺ������:>");
			scanf("%d", &(pc->data[pos].age));
			printf("�������޸ĺ���Ա�:>");
			scanf("%s", pc->data[pos].sex);
			printf("�������޸ĺ�ĵ绰:>");
			scanf("%s", pc->data[pos].tele);
			printf("�������޸ĺ�ĵ�ַ:>");
			scanf("%s", pc->data[pos].addr);
			//��ʾ�޸ĳɹ�
			printf("�޸ĳɹ�\n");
		}
	}
//��ʾͨѶ¼5
	void ShowContact(const Contact* pc)
	{
		int i = 0;
		//�Ҷ�����ʾ
		printf("%20s\t%5s\t%5s\t%12s\t%15s\n",
			"name", "age", "sex", "tele", "addr");
		//�������ʾ
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
// ����������������ϵ��6
	// �ο����룺https://www.runoob.com/cprogramming/c-examples-lexicographical-order.html
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
		printf("������ɣ�\n");
	}
	// ���������ϵ��7
	void ClsContact(Contact* pc)
	{
		pc->sz = 0;
		printf("��ճɹ�\n");
	}






