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
//声明棋盘初始化函数
void InitBoard(char borad[999][999], int rows, int cols, char set);
//声明打印函数
//void Print(char borad[999][999], int row, int col);
//声明布置雷函数
void SetMine(char mine[999][999], int row, int col,int count);
//声明排查雷函数
void FindMine(char mine[999][999], char show[999][999], int row, int col, int count);
//声明打印排查出雷的信息
void PrintShow(char borad[999][999], int row, int col);
//声明打印全部棋盘（有雷的信息）
PrintMine(char borad[999][999], int row, int col);
//声明展开一片函数
void  UnfloodMineArround(char  mine[999][999], char show[999][999], int row, int col, int x, int y);
//声明游戏成功结束的函数
int Success(char show[999][999], int row, int col);

