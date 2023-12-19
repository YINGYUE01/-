#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1
//棋盘初始化
void InitBoard(char borad[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			borad[i][j] = set;
		}
	}
}
void Print(char borad[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("-------扫雷游戏-------\n");
	for(i=0;i<=col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", borad[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;	
		if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
				count--;
			}		
	}
}
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
				count++;
		}

	}
	return count;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col)
{
	int x=0;
	int y=0;
	int win = 0;
	while (win<ROW*COL - Easy_count)
	{
		printf("请输入你要排查的坐标：");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					system("cls");
					printf("很遗憾，你被炸死了！\n");
					Print(mine, ROW, COL);
					break;
				}
				else
				{
					int count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';
					system("cls");
					Print(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("该坐标已经排查了，请重新输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	if (win ==row * col - Easy_count)
	{
		system("cls");
		printf("恭喜你，排雷成功！\n");
		Print(mine, ROW, COL);
	}
}
