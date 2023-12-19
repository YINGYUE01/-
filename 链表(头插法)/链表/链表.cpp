#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//声明链表结点的类型
typedef	struct node
{
	int date;         //数据域
	struct node *next;//指针域
}NODE;
//创建一个头结点
NODE* init()
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->date = 0;
	temp->next = NULL;
	return temp;
}
//头插法  增加元素
void sr(NODE* head,int date)
{
	//申请新内存
	NODE*s = (NODE*)malloc(sizeof(NODE));
	s->date = date;      //给新结点存数据
	s->next = head->next;//将新结点的指针域指向原来的首元结点
	head->next = s;      //将头结点的指针域指向新结点
}
//打印链表的数据
void print(NODE* head)
{
	NODE* p = head->next;        //定义一个新结点p，将首元结点传给p
	while (p!=NULL)
	{
		printf("%d-> ", p->date);//打印每个结点的数据
		p = p->next;             //打印一个后p向后移动一个结点
	}
	printf("NULL");
}
int main()
{
	NODE *head=NULL;
	head = init();
	//循环开创新结点并输入数据
	for (int i = 1; i <= 5; i++)
	{
		sr(head, i);
	}
	print(head);//打印链表的数据
}
