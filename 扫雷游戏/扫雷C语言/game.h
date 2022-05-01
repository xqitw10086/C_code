#define _CRT_SECURE_NO_WARNINGS 1

//程序所需要的头文件
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//程序所需要的数据
//为了能获取一周的数据，棋盘为9*9，则实际棋盘为11*11
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
//本次游戏的埋雷个数
#define NUM 10

//初始化二维数组
void InitBoard(char board[ROWS][COLS], int row, int col , char x);

//打印二维数组
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void Arrange(char board[ROWS][COLS], int row, int col);

//排查雷
int FindMine(char board1[ROWS][COLS],char board2[ROWS][COLS],  int row, int col);