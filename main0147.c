#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//包括的函数有：system realloc
#include <assert.h>//包括的函数有：assert
#include <string.h>//包括的函数有：memset、
#define SEQLIST_DEFAULT_SIZE 1//定义默认开辟的空间大小为1个元素，只能为1，不要乱改，否则以下代码要改变
#define SEQLIST_INC_SIZE 1 //每扩容一次，增加1个元素，只能为1，不要乱改，否则以下代码要改变
//第一种方法
//void rotate(int* nums, int numsSize, int k) {
//	int numsSize1 = numsSize;
//	while (k--)
//	{
//		int tem = nums[numsSize - 1];//保存最后一个数据
//		for (int i = numsSize - 1; i > 0; --i)//顺序表的数据往后移动
//			nums[i] = nums[i - 1];
//		//头插数据
//		nums[0] = tem;//将最后一个数据放在首位
//	}
//}
//第二种方法：①使用额外的数组
//void rotate(int* nums, int numsSize, int k) {
//	int* newArr = (int*)malloc(sizeof(int) * numsSize);
//	assert(newArr != NULL); //开辟空间成功判断
//	for (int i = 0; i < numsSize; ++i) {
//		newArr[(i + k) % numsSize] = nums[i];//这里的赋值操作很妙
//	}
//	for (int i = 0; i < numsSize; ++i) {
//		nums[i] = newArr[i];
//	}
//}
//②
//void rotate(int* nums, int numsSize, int k) {
//	int* newArr = (int*)malloc(sizeof(int) * numsSize);
//	assert(newArr != NULL); //开辟空间成功判断
//	for (int i = 0; i < numsSize - k; ++i) {
//		newArr[i + k] = nums[i];
//	}
//	for (int i = numsSize - k; i < numsSize; ++i) {
//		newArr[i-(numsSize - k)] = nums[i];
//	}
//	for (int i = 0; i < numsSize; ++i) {
//		nums[i] = newArr[i];
//	}
//}

//方法三：环状替换
//int gcd(int a, int b) {//求a、b的最大公约数，最大的公约数即为遍历的圈数
//	return b ? gcd(b, a % b) : a;
//}
//
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b, *b = t;
//}
//
//void rotate(int* nums, int numsSize, int k) {
//	k = k % numsSize;
//	int count = gcd(k, numsSize);
//	for (int start = 0; start < count; ++start) {
//		int current = start;
//		int prev = nums[start];
//		do {
//			int next = (current + k) % numsSize;
//			swap(&nums[next], &prev);
//			current = next;
//		} while (start != current);
//	}
//}
//方法四：数组翻转
void swap(int* a, int* b) {
	int t = *a;
	*a = *b, * b = t;
}

void reverse(int* nums, int start, int end) {
	while (start < end) {
		swap(&nums[start], &nums[end]);
		start += 1;
		end -= 1;
	}
}

void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}

void Destroy(int* pst, int* ASize)//摧毁（把申请的动态内存直接释放）
{
	assert(pst);
	free(pst);//释放空间
	pst = NULL; // 预防野指针
	*ASize = 0;
}
int main()
{
	int* nums = (int*)malloc(sizeof(int) * SEQLIST_DEFAULT_SIZE);
	assert(nums != NULL); //开辟空间成功判断
	memset(nums, 0, sizeof(int) * SEQLIST_DEFAULT_SIZE);//将内存的值初始化为0
	int numsSize = 0;
	int K = 0;
	//Init(A);//将A指向的空间进行初始化
	numsSize = SEQLIST_DEFAULT_SIZE;
	int i = 0;
	printf("请输入一个数组，以空格隔开:>");
	while (1)//给A赋值
	{
		scanf("%d", nums + i);
		if (getchar() == '\n')//吸收空格和回车
			break;
		else
		{
			i++;
			int* new_base = (int*)realloc(nums, sizeof(int) * (numsSize + SEQLIST_INC_SIZE));//扩充一个元素的容量
			if (new_base == NULL)
			{
				printf("扩容失败.\n");
				return NULL;
			}
			nums = new_base;
			numsSize += SEQLIST_INC_SIZE;//空间增加		
		}
	}
	printf("请输入一个非负整数:>");
	scanf("%d", &K);
	rotate(nums, numsSize, K);
	for (i = 0; i < numsSize; i++)//向顺序表中写入数据
	{
		printf("%d ", nums[i]);
	}
	Destroy(nums, &numsSize);//摧毁A,防止内存泄露
	system("pause");//暂停一下
	return 0;
}