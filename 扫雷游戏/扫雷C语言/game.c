#define _CRT_SECURE_NO_WARNINGS 1
#include  "game.h"

//二维数组初始化
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

//棋盘打印
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

//布置雷
void Arrange(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (count != NUM)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		//if ((strcmp(board[i][j],'0'))==0)  会报错
		if(board[i][j] == '0')
		{
			board[i][j] = '1';
			count++;
		}
	}
}

//返回周围一周雷的个数
int RetNum(char board[ROWS][COLS], int i, int j)
{
	return board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j - 1] + board[i][j + 1]
		+ board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1] - 8 * '0';
}

//排查雷
//若当前坐标恰好是雷：输出玩家失败
//若当前坐标不是雷：显示当前坐标一周的雷的个数
int FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int x, int y)
{
	if (board1[x][y] == '1')
	{
		printf("爆炸!玩家失败！！！\n");
		printf("爆炸!玩家失败！！！\n");
		printf("爆炸!玩家失败！！！\n");
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