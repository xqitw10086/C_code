#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//���̳�ʼ��
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col-1)
			{
				printf("|");
			}
			else
			{
				printf("\n");
			}
		}
		if (i != row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j != col - 1)
				{
					printf("|");
				}
				else
				{
					printf("\n");
				}
			}
		}
		
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	printf("�������Ϊ*\n");
	//DisplayBoard(board, row, col);
	do {
		flag = 0;
		printf("������������λ�õ����꣨����1�ո�2����");
		scanf("%d %d", &i, &j);
		//�ж��Ƿ�Խ��
		if (i<1 || i>row || j<1 || j>col)
		{
			flag = 1;
			printf("����������������룡\n");
		}
		//�жϸ�λ���Ƿ���������
		else if (board[i-1][j-1] != ' ')   //��д����ʱ���Ǹ������1��
		{
			flag = 1;
			printf("��λ���������ӣ�������ѡ��\n");
		}
		else
		{
			board[i-1][j-1] = '*';
		}
	} while (flag);
	
}

//��������
void ComputeMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	//DisplayBoard(board, row, col);
	printf("���Ե�����Ϊ#\n");
	do {
		flag = 0;
		i = rand() % row;
		j = rand() % col;
		
		//printf("%d %d\n", i+1, j+1);
		//����һ����Խ��
		//�жϸ�λ���Ƿ���������
		if (board[i][j] != ' ')
		{
			flag = 1;
		}
		else
		{
			board[i][j] = '#';
		}
	} while (flag);

}

//�ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
				return 0;
		}
	}
	return 1;
}

////�ж���Ӯ ������ δ�ɹ�
//int IsWin(char board[ROW][COL], int row, int col,  char chess)
//{
//	//���1������ӻ�ʤ�����0����Ϸ���������2��Ϊƽ��
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	int count = 0;
//	for (i = 0; i < row; i++)
//	{
//		//���Ƿ����
//		count = 0;
//		for (j = 0; j < col; j++)
//		{
//			if (strcmp(board[i][j], chess) != 0)
//			{
//				flag = 1;
//				break;
//			}
//			count++;
//			if (count == row)//���о���ͬ
//				return 1;
//		}
//		//���Ƿ����
//		count = 0;
//		for (j = 0; j < col; j++)
//		{
//			if (strcmp(board[j][i], chess) != 0)
//			{
//				flag = 1;
//				break;
//			}
//			count++;
//			if (count == col)//���о���ͬ
//				return 1;
//		}
//	}
//	return 0;
//}

//�ж��Ƿ��ʤ ������
//���1������ӻ�ʤ�����0����Ϸ������
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';
}