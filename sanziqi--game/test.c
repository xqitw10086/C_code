#define _CRT_SECURE_NO_WARNINGS 1
//game.h包含了程序需要的变量、头文件和函数声明
#include"game.h"

void menu()
{
	printf("####################\n");
	printf("###### 1.play  #####\n");
	printf("###### 2.exit  #####\n");
	printf("####################\n");
}

//实现游戏函数，其中具体操作存放于game.c
void game()
{
	srand((unsigned int)time(NULL));
	//创建数组存储棋盘相关数据
	char board[ROW][COL] = { 0 };
	//初始化棋盘数据 -- 存储空格使其显示为空
	InitBoard(board, ROW, COL);
	//打印当前棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while(1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputeMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		/*if (IsWin(board, ROW, COL, '*'))
		{
			printf("玩家获胜！\n");
			break;
		}
		else if (IsWin(board, ROW, COL, '#'))
		{
			printf("电脑获胜！\n");
			break;
		}
		else if (IsFull(board, ROW, COL))
		{
			printf("此局为平局！\n");
			break;
		}*/
	} 
	if (ret == '*')
	{
		printf("玩家获胜！\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜！\n");
	}
	else
	{
		printf("二者平局！\n");
	}
	
}

int main()
{
	int input=0;
	do{
		menu();
		printf("请输入你的选择(1/2)：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (2 != input);
	return 0;
}