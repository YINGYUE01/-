#pragma once
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//#include<Windows.h>
#define ROW 9
#define COL 9
#define COLS COL+2
#define ROWS ROW+2
#define Easy_count 10
//�������̳�ʼ������
void InitBoard(char borad[ROWS][COLS], int rows, int cols, char set);
//������ӡ����
void Print(char borad[ROWS][COLS], int row, int col);
//���������׺���
void SetMine(char mine[ROWS][COLS], int row, int col);
//�����Ų��׺���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//������ӡ�Ų���׵���Ϣ
void PrintShow(char borad[ROWS][COLS], int row, int col);
//������ӡȫ�����̣����׵���Ϣ��
PrintMine(char borad[ROWS][COLS], int row, int col);

