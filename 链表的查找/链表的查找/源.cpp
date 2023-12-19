#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//void fun(N* head, int n);
typedef struct node
{
	int id;
	struct node* next;
}N;
N* inti()
{
	N* p = (N*)malloc(sizeof(N));
	p->id = 0;
	p->next = NULL;
	return p;
}
void insert(N* head, int n)
{
	N* temp = head;
	N* s;
	for (int i = 0; i < n; i++)
	{
		s = (N*)malloc(sizeof(N));
		scanf("%d", &s->id);
		temp->next = s;
		s->next = NULL;
		temp = s;
	}
}
void print(N* head)
{
	N* p = head->next;
	while (p != NULL)
	{
		printf("%d->", p->id);
		Sleep(500);
		p = p->next;
	}
	printf("NULL");

}
void fun(N* head, int n)
{
	int count = 0;
	N* f = head->next;
	while (f != NULL)
	{
		if (f->id == n)
		{
			printf("%d\n", f->id);
			count++;
		}
		f = f->next;
	}
	if (count > 0)
		printf("��%d��", count);
	else
		printf("û�����Ԫ��");
}
int main()
{
	int k;
	N* head = inti();
	int n;
	scanf("%d", &n);
	insert(head, n);
	print(head);
	scanf("%d", &k);
	fun(head, k);
}