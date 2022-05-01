#define _CRT_SECURE_NO_WARNINGS 1

#include  "game.h"

void menu()
{
	printf("####################\n");
	printf("#####  1 play  #####\n");
	printf("#####  2 exit  #####\n");
	printf("####################\n");
}

void game()
{
	//为了达到初始不可见的要求，用*存放，则存放数组应为char类型
	//使用两个数组，一个存放布置雷的数据，一个存放排查雷的数据
	char board1[ROWS][COLS] = { 0 };  //布置雷
	char board2[ROWS][COLS] = { 0 };  //排查雷

	//初始化二维数组
	InitBoard(board1, ROWS, COLS, '0');
	InitBoard(board2, ROWS, COLS, '*');
	//打印二维数组
	//DisplayBoard(board1, ROW, COL);
	DisplayBoard(board2, ROW, COL);
	//布置雷
	Arrange(board1, ROW, COL);
	//DisplayBoard(board1, ROW, COL);
	//排查雷
	//重复排查，直到玩家失败或排除结束
	int x = 0;
	int y = 0;
	int count = ROW * COL - NUM;
	int ret = 0;
	do {
		printf("请输入你想排查雷的坐标（例如：1空格2）：");
		scanf("%d %d", &x, &y);
		ret = FindMine(board1, board2, x, y);
		if (0 == ret)
		{
			DisplayBoard(board1, ROW, COL);
			break;
		}
		else
		{
			DisplayBoard(board2, ROW, COL);
			count--;
		}
	} while (count);
	if (count == 0)
	{
		printf("玩家胜利！！！\n");
		printf("玩家胜利！！！\n");
		printf("玩家胜利！！！\n");
	}


}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		//打印菜单
		menu();
		printf("请输入你的操作内容：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("开始游戏\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input != 2);
	

	return 0;
}