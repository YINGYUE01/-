#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//棋盘初始化
void InitBoard(char borad[999][999], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			borad[i][j] = set;
		}
	}
}
//打印show棋盘
void PrintShow(char borad[999][999], int row, int col)
{
	int i, j;
	printf("-------扫雷游戏-------\n");
	for (i = 0; i <= col; i++)
	{
		printf("\033[33m%2d\033[0m ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("\033[33m%2d\033[0m ", i);
		for (j = 1; j <= col; j++)
		{
			if (borad[i][j] != '*')
			{
				printf("\033[32m%2c\033[0m ", borad[i][j]);
			}
			else
			{
				printf("\033[31m%2c\033[0m ", borad[i][j]);
			}
		}
		printf("\n");
	}
}
//打印mine棋盘
PrintMine(char borad[999][999], int row, int col)
{
	int i, j;
	printf("-------扫雷游戏-------\n");
	for (i = 0; i <= col; i++)
	{
		printf("\033[33m%2d\033[0m ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("\033[33m%2d\033[0m ", i);
		for (j = 1; j <= col; j++)
		{
			if (borad[i][j] == '1')
			{
				//printf("\033[32m%2c\033[0m ", borad[i][j]);
				printf("\033[31m%2c\033[0m ", borad[i][j]);

			}
			else
			{
				//printf("\033[31m%2c\033[0m ", borad[i][j]);
				printf("\033[32m%2c\033[0m ", borad[i][j]);

			}
		}
		printf("\n");
	}
}
//设置雷
void SetMine(char mine[999][999], int row, int col, int count)
{
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
//int GetMineCount(char mine[ROWS][COLS], int x, int y)
//{
//	return (mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] +mine[x - 1][y] + mine[x - 1][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y + 1] + mine[x + 1][y] - 8 * '0');
//}
//获取周围雷的数量
int GetMineCount(char mine[999][999], int x, int y)
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
// 周围都不是雷则展开一片
void  UnfloodMineArround(char  mine[999][999], char show[999][999], int row, int col, int x, int y)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法
	{
		int count = GetMineCount(mine, x, y);
		show[x][y] = count + '0';
		if (count == 0)
		{
			for (int i = x - 1; i <= x + 1; i++)
			{
				for (int j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')
					{
						UnfloodMineArround(mine, show, row, col, i, j);
					}
				}
			}
		}
		else
		{
			return;
		}
	}
	else
		return;

}
//查找雷
void FindMine(char mine[999][999], char show[999][999], int row, int col, int count)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - count)//游戏结束条件
	{
		printf("请输入你要排查的坐标：");

		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标合法
		{
			if (show[x][y] == '*')//排除重复排查的坐标
			{
				if (mine[x][y] == '1')
				{
					system("cls");
					printf("很遗憾，你被炸死了！\n");//被炸死结束
					PrintMine(mine, row, col);
					break;
				}
				else
				{
					UnfloodMineArround(mine, show, row, col, x, y);
					system("cls");
					int count1 = Success(show, row, col);//判断排雷成功则跳出循环结束游戏
					if (count1 == count)
					{
						system("cls");
						printf("恭喜你，排雷成功！\n");
						PrintMine(mine, row, col);
						break;
					}
					PrintShow(show, row, col);
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
	if (win == row * col - count)//结束
	{
		system("cls");
		printf("恭喜你，排雷成功！\n");
		PrintMine(mine, row, col);
	}
}
//排雷成功的判断
int Success(char show[999][999], int row, int col)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{

		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
				count++;
		}
	}
	return count;
}