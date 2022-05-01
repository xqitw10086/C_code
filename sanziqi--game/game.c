#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//棋盘初始化
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

//打印棋盘
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

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	printf("你的棋子为*\n");
	//DisplayBoard(board, row, col);
	do {
		flag = 0;
		printf("请输入你所下位置的坐标（例如1空格2）：");
		scanf("%d %d", &i, &j);
		//判断是否越界
		if (i<1 || i>row || j<1 || j>col)
		{
			flag = 1;
			printf("输入错误，请重新输入！\n");
		}
		//判断该位置是否已有棋子
		else if (board[i-1][j-1] != ' ')   //编写代码时忘记给这里减1了
		{
			flag = 1;
			printf("该位置已有棋子，请重新选择！\n");
		}
		else
		{
			board[i-1][j-1] = '*';
		}
	} while (flag);
	
}

//电脑下棋
void ComputeMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	//DisplayBoard(board, row, col);
	printf("电脑的棋子为#\n");
	do {
		flag = 0;
		i = rand() % row;
		j = rand() % col;
		
		//printf("%d %d\n", i+1, j+1);
		//电脑一定不越界
		//判断该位置是否已有棋子
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

//判断棋盘是否已满
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

////判断输赢 机动版 未成功
//int IsWin(char board[ROW][COL], int row, int col,  char chess)
//{
//	//输出1则该棋子获胜，输出0则游戏继续，输出2则为平局
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	int count = 0;
//	for (i = 0; i < row; i++)
//	{
//		//行是否相等
//		count = 0;
//		for (j = 0; j < col; j++)
//		{
//			if (strcmp(board[i][j], chess) != 0)
//			{
//				flag = 1;
//				break;
//			}
//			count++;
//			if (count == row)//该行均相同
//				return 1;
//		}
//		//列是否相等
//		count = 0;
//		for (j = 0; j < col; j++)
//		{
//			if (strcmp(board[j][i], chess) != 0)
//			{
//				flag = 1;
//				break;
//			}
//			count++;
//			if (count == col)//该列均相同
//				return 1;
//		}
//	}
//	return 0;
//}

//判断是否获胜 三子棋
//输出1则该棋子获胜，输出0则游戏继续，
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