//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<windows.h>
//#include <time.h>
//#include<stdlib.h>
//
//void menu()
//{
//	printf("********************\n");
//	printf("****** 1 play ******\n");
//	printf("****** 0 exit ******\n");
//	printf("********************\n");
//}
//
//void game()
//{
//	int random_num = rand() % 100 + 1;
//	//printf("%d", random_num);
//	int input = 0;
//	while (1)
//	{
//		printf("�����������µ����֣�");
//		scanf("%d", &input);
//		if (input < random_num)
//			printf("�������̫С�ˣ�\n");
//		else if(input>random_num)
//			printf("�������̫���ˣ�\n");
//		else
//		{
//			printf("��ϲ�¶ԣ�\n");
//			Sleep(2000);
//			system("cls");   //��ɺ󱣳���ʾһ��Ȼ������
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("�������Ҫ��(0/1):");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;  //ÿһ��case��default����ȶ�����break
//		case 0:
//			break;
//		default:
//			printf("����������������롣\n");
//			Sleep(500);
//			system("cls");
//			break;
//		}
//	}while (input); //input���ڼ�input==1
//	return 0;
//}