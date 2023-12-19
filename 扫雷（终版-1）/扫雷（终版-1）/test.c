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
	printf("*********  1.简单      *******\n");
	printf("*********  2.中等      *******\n");
	printf("*********  3.困难      *******\n");
	printf("*********  4.自定义    *******\n");
	printf("*********  0.Exit      *******\n");
	printf("******************************\n");
	printf("请选择：");
}
void game()
{

	//棋盘初始化
	InitBoard(mine, ROWS, COLS, '0');//
	InitBoard(show, ROWS, COLS, '*');//
	//布置雷
	SetMine(mine, ROW, COL, Count);
	PrintShow(show, ROW, COL);
	//PrintMine(mine, ROW, COL);
	//排查雷
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

			printf("所用时间为：%d", (t2 - t1) / 1000);
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


			printf("所用时间为：%d", (t3 - t1) / 1000);
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
			printf("所用时间为：%d", (t4 - t1) / 1000);
			printf("\n");

			break;
		case 4:
			printf("请输入棋盘大小：");
			scanf("%d %d", &ROW, &COL);
			ROWS = ROW + 2;
			COLS = COL + 2;
			printf("请输入雷的数量：");
			scanf("%d", &Count);
			clock_t t6 = clock();
			game();
			clock_t t5 = clock();

			printf("所用时间为：%d", (t5 - t6) / 1000);
			printf("\n");
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (m);
	return 0;
}