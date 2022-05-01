#define _CRT_SECURE_NO_WARNINGS 1
//game.h�����˳�����Ҫ�ı�����ͷ�ļ��ͺ�������
#include"game.h"

void menu()
{
	printf("####################\n");
	printf("###### 1.play  #####\n");
	printf("###### 2.exit  #####\n");
	printf("####################\n");
}

//ʵ����Ϸ���������о�����������game.c
void game()
{
	srand((unsigned int)time(NULL));
	//��������洢�����������
	char board[ROW][COL] = { 0 };
	//��ʼ���������� -- �洢�ո�ʹ����ʾΪ��
	InitBoard(board, ROW, COL);
	//��ӡ��ǰ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while(1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		ComputeMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		/*if (IsWin(board, ROW, COL, '*'))
		{
			printf("��һ�ʤ��\n");
			break;
		}
		else if (IsWin(board, ROW, COL, '#'))
		{
			printf("���Ի�ʤ��\n");
			break;
		}
		else if (IsFull(board, ROW, COL))
		{
			printf("�˾�Ϊƽ�֣�\n");
			break;
		}*/
	} 
	if (ret == '*')
	{
		printf("��һ�ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ��\n");
	}
	else
	{
		printf("����ƽ�֣�\n");
	}
	
}

int main()
{
	int input=0;
	do{
		menu();
		printf("���������ѡ��(1/2)��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (2 != input);
	return 0;
}