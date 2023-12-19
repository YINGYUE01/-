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
//声明棋盘初始化函数
void InitBoard(char borad[ROWS][COLS], int rows, int cols, char set);
//声明打印函数
void Print(char borad[ROWS][COLS], int row, int col);
//声明布置雷函数
void SetMine(char mine[ROWS][COLS], int row, int col);
//声明排查雷函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//声明打印排查出雷的信息
void PrintShow(char borad[ROWS][COLS], int row, int col);
//声明打印全部棋盘（有雷的信息）
PrintMine(char borad[ROWS][COLS], int row, int col);

