#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
int n;
void fun();
int main()
{
	int  i, j, k, ret, m;
	int count = 0;
	fun();
	while (n == 1)
	{
		srand((unsigned int)time(NULL));
		k = rand();
		ret = k % 100 + 1;
		do
		{

			printf("请输入你要猜的数字：");
			scanf("%d", &m);
			if (m == ret)
			{
				printf("恭喜你猜对了：\n");
				printf("数字是：%d\n", ret);
				break;
				count++;
			}
			else if (m > ret)
			{
				printf("猜大了\n");
				continue;
			}
			else
			{
				printf("猜小了\n");
				continue;
			}
		} while (count == 0);
		fun();
	}
}
void fun()
{
	printf("********************\n");
	printf("****** 1.play ******\n");
	printf("****** 2.exit ******\n");
	printf("********************\n");
	printf("请输入：");
	scanf("%d", &n);
}
