#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void quit()
{
	printf("************************\n");
	printf("*********1.Play*********\n");
	printf("*********0.Exit*********\n");
	printf("************************\n");
	printf("�����룺");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//���̳�ʼ��
	InitBoard(mine, ROWS, COLS, '0');//
	InitBoard(show, ROWS, COLS, '*');//
	//������
	SetMine(mine, ROW, COL);
	PrintShow(show, ROW, COL);
	//PrintMine(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int m;
	do
	{
		srand((unsigned)time(NULL));
		quit();
		scanf("%d", &m);
		switch (m)
		{
		case 1:
			game();
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