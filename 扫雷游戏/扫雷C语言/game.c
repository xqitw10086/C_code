#define _CRT_SECURE_NO_WARNINGS 1
#include  "game.h"

//��ά�����ʼ��
void InitBoard(char board[ROWS][COLS], int row, int col, char x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = x;
		}
	}
}

//���̴�ӡ
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf( "--------------------\n" );
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j <= col; j++)
		{
			if (0 == i)
			{
				printf("%d ", j);
			}
			else if (0 == j)
			{
				printf("%d ", i);
			}
			else
			{
				printf("%c ", board[i][j]);
			}
		 }
		printf("\n");
	}
	printf("--------------------\n");
}

//������
void Arrange(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (count != NUM)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		//if ((strcmp(board[i][j],'0'))==0)  �ᱨ��
		if(board[i][j] == '0')
		{
			board[i][j] = '1';
			count++;
		}
	}
}

//������Χһ���׵ĸ���
int RetNum(char board[ROWS][COLS], int i, int j)
{
	return board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j - 1] + board[i][j + 1]
		+ board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1] - 8 * '0';
}

//�Ų���
//����ǰ����ǡ�����ף�������ʧ��
//����ǰ���겻���ף���ʾ��ǰ����һ�ܵ��׵ĸ���
int FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y)
{
	if (board1[x][y] == '1')
	{
		printf("��ը!���ʧ�ܣ�����\n");
		printf("��ը!���ʧ�ܣ�����\n");
		printf("��ը!���ʧ�ܣ�����\n");
		return 0;
	}
	else {
		int ret = 0;
		ret = RetNum(board1, x, y)+48;
		//printf("%d\n", ret);
		board2[x][y] = (char)ret;
		return 1;
	}
	

}