#define _CRT_SECURE_NO_WARNINGS 1

//��������Ҫ��ͷ�ļ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//��������Ҫ������
//Ϊ���ܻ�ȡһ�ܵ����ݣ�����Ϊ9*9����ʵ������Ϊ11*11
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
//������Ϸ�����׸���
#define NUM 10

//��ʼ����ά����
void InitBoard(char board[ROWS][COLS], int row, int col , char x);

//��ӡ��ά����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//������
void Arrange(char board[ROWS][COLS], int row, int col);

//�Ų���
int FindMine(char board1[ROWS][COLS],char board2[ROWS][COLS],  int row, int col);