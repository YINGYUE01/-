#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//���������������
typedef	struct node
{
	int date;         //������
	struct node *next;//ָ����
}NODE;
//����һ��ͷ���
NODE* init()
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->date = 0;
	temp->next = NULL;
	return temp;
}
//ͷ�巨  ����Ԫ��
void sr(NODE* head,int date)
{
	//�������ڴ�
	NODE*s = (NODE*)malloc(sizeof(NODE));
	s->date = date;      //���½�������
	s->next = head->next;//���½���ָ����ָ��ԭ������Ԫ���
	head->next = s;      //��ͷ����ָ����ָ���½��
}
//��ӡ���������
void print(NODE* head)
{
	NODE* p = head->next;        //����һ���½��p������Ԫ��㴫��p
	while (p!=NULL)
	{
		printf("%d-> ", p->date);//��ӡÿ����������
		p = p->next;             //��ӡһ����p����ƶ�һ�����
	}
	printf("NULL");
}
int main()
{
	NODE *head=NULL;
	head = init();
	//ѭ�������½�㲢��������
	for (int i = 1; i <= 5; i++)
	{
		sr(head, i);
	}
	print(head);//��ӡ���������
}
