#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int ROW;
int COL;
int ROWS;
int COLS;
int Count;
char mine[999][999];
char show[999][999];
void quit()
{
	printf("******************************\n");
	printf("*********  1.��      *******\n");
	printf("*********  2.�е�      *******\n");
	printf("*********  3.����      *******\n");
	printf("*********  4.�Զ���    *******\n");
	printf("*********  0.Exit      *******\n");
	printf("******************************\n");
	printf("��ѡ��");
}
void game()
{

	//���̳�ʼ��
	InitBoard(mine, ROWS, COLS, '0');//
	InitBoard(show, ROWS, COLS, '*');//
	//������
	SetMine(mine, ROW, COL, Count);
	PrintShow(show, ROW, COL);
	//PrintMine(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL, Count);
	//
}
int main()
{
	int m;
	do
	{

		srand((unsigned)time(NULL));
		quit();
		scanf("%d", &m);
		clock_t t1 = clock();
		switch (m)
		{
		case 1:
			ROW = 9;
			COL = 9;
			ROWS = ROW + 2;
			COLS = COL + 2;
			Count = 10;
			game();
			clock_t t2 = clock();

			printf("����ʱ��Ϊ��%d", (t2 - t1) / 1000);
			printf("\n");
			break;
		case 2:
			ROW = 16;
			COL = 16;
			ROWS = ROW + 2;
			COLS = COL + 2;
			Count = 40;
			game();
			clock_t t3 = clock();


			printf("����ʱ��Ϊ��%d", (t3 - t1) / 1000);
			printf("\n");
			break;
		case 3:
			ROW = 32;
			COL = 32;
			ROWS = ROW + 2;
			COLS = COL + 2;
			Count = 150;
			game();
			clock_t t4 = clock();
			printf("����ʱ��Ϊ��%d", (t4 - t1) / 1000);
			printf("\n");

			break;
		case 4:
			printf("���������̴�С��");
			scanf("%d %d", &ROW, &COL);
			ROWS = ROW + 2;
			COLS = COL + 2;
			printf("�������׵�������");
			scanf("%d", &Count);
			clock_t t6 = clock();
			game();
			clock_t t5 = clock();

			printf("����ʱ��Ϊ��%d", (t5 - t6) / 1000);
			printf("\n");
			break;
		case 0:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (m);
	return 0;
}