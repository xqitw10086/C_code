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
	//Ϊ�˴ﵽ��ʼ���ɼ���Ҫ����*��ţ���������ӦΪchar����
	//ʹ���������飬һ����Ų����׵����ݣ�һ������Ų��׵�����
	char board1[ROWS][COLS] = { 0 };  //������
	char board2[ROWS][COLS] = { 0 };  //�Ų���

	//��ʼ����ά����
	InitBoard(board1, ROWS, COLS, '0');
	InitBoard(board2, ROWS, COLS, '*');
	//��ӡ��ά����
	//DisplayBoard(board1, ROW, COL);
	DisplayBoard(board2, ROW, COL);
	//������
	Arrange(board1, ROW, COL);
	//DisplayBoard(board1, ROW, COL);
	//�Ų���
	//�ظ��Ų飬ֱ�����ʧ�ܻ��ų�����
	int x = 0;
	int y = 0;
	int count = ROW * COL - NUM;
	int ret = 0;
	do {
		printf("�����������Ų��׵����꣨���磺1�ո�2����");
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
		printf("���ʤ��������\n");
		printf("���ʤ��������\n");
		printf("���ʤ��������\n");
	}


}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		//��ӡ�˵�
		menu();
		printf("��������Ĳ������ݣ�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("��ʼ��Ϸ\n");
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input != 2);
	

	return 0;
}