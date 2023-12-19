#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//���̳�ʼ��
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
//��ӡshow����
void PrintShow(char borad[999][999], int row, int col)
{
	int i, j;
	printf("-------ɨ����Ϸ-------\n");
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
//��ӡmine����
PrintMine(char borad[999][999], int row, int col)
{
	int i, j;
	printf("-------ɨ����Ϸ-------\n");
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
//������
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
//��ȡ��Χ�׵�����
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
// ��Χ����������չ��һƬ
void  UnfloodMineArround(char  mine[999][999], char show[999][999], int row, int col, int x, int y)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����Ϸ�
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
//������
void FindMine(char mine[999][999], char show[999][999], int row, int col, int count)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - count)//��Ϸ��������
	{
		printf("��������Ҫ�Ų�����꣺");

		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж�����Ϸ�
		{
			if (show[x][y] == '*')//�ų��ظ��Ų������
			{
				if (mine[x][y] == '1')
				{
					system("cls");
					printf("���ź����㱻ը���ˣ�\n");//��ը������
					PrintMine(mine, row, col);
					break;
				}
				else
				{
					UnfloodMineArround(mine, show, row, col, x, y);
					system("cls");
					int count1 = Success(show, row, col);//�ж����׳ɹ�������ѭ��������Ϸ
					if (count1 == count)
					{
						system("cls");
						printf("��ϲ�㣬���׳ɹ���\n");
						PrintMine(mine, row, col);
						break;
					}
					PrintShow(show, row, col);
					win++;
				}
			}
			else
			{
				printf("�������Ѿ��Ų��ˣ�����������\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (win == row * col - count)//����
	{
		system("cls");
		printf("��ϲ�㣬���׳ɹ���\n");
		PrintMine(mine, row, col);
	}
}
//���׳ɹ����ж�
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