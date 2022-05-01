#define _CRT_SECURE_NO_WARNINGS 1

//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//符号的定义
#define ROW 3
#define COL 3

//函数的声明

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputeMove(char board[ROW][COL], int row, int col);

//判断当前游戏状态
char IsWin(char board[ROW][COL], int row, int col);

//判断棋盘是否已满
int IsFull(char board[ROW][COL], int row, int col);