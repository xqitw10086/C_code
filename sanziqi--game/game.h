#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ��İ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//���ŵĶ���
#define ROW 3
#define COL 3

//����������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputeMove(char board[ROW][COL], int row, int col);

//�жϵ�ǰ��Ϸ״̬
char IsWin(char board[ROW][COL], int row, int col);

//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);