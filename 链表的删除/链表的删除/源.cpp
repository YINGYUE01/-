#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct node
{
	int date;
	struct node* next;
}NODE;
//
NODE* inti()
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->date = 0;
	p->next = NULL;
	return p;
}
//输出链表函数
void print(NODE* head)
{
	NODE* p = head->next;

	while (p != NULL)
	{
		printf("->%d ", p->date);
		Sleep(500);
		p = p->next;
	}
	printf("NULL");
}
//尾插法 
void set(NODE* head, int n)
{
	NODE* s;
	NODE* temp;
	temp = head;
	for (int i = 0; i < n; i++)
	{
		s = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &s->date);
		s->next = NULL;
		temp->next = s;
		temp = s;
	}
}
void del(NODE* head, int date)
{
	NODE* p = head->next;
	while (p != NULL)
	{
		if (p->next->date == date)
		{
			p->next = p->next->next;
		}
		p = p->next;
	}

}
int main()
{
	NODE* head;
	head = inti();
	int n = 5;
	set(head, n);
	print(head);
	int date;
	scanf("%d", &date);
	del(head, date);
	print(head);
}
