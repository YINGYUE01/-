#pragma once
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
//#include<Windows.h>
//#define ROW 9
//#define COL 9
//#define COLS COL+2
//#define ROWS ROW+2
#define Easy_count 10
//�������̳�ʼ������
void InitBoard(char borad[999][999], int rows, int cols, char set);
//������ӡ����
//void Print(char borad[999][999], int row, int col);
//���������׺���
void SetMine(char mine[999][999], int row, int col,int count);
//�����Ų��׺���
void FindMine(char mine[999][999], char show[999][999], int row, int col, int count);
//������ӡ�Ų���׵���Ϣ
void PrintShow(char borad[999][999], int row, int col);
//������ӡȫ�����̣����׵���Ϣ��
PrintMine(char borad[999][999], int row, int col);
//����չ��һƬ����
void  UnfloodMineArround(char  mine[999][999], char show[999][999], int row, int col, int x, int y);
//������Ϸ�ɹ������ĺ���
int Success(char show[999][999], int row, int col);

