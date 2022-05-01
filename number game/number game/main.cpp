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
//		printf("请输入你所猜的数字：");
//		scanf("%d", &input);
//		if (input < random_num)
//			printf("你的数字太小了！\n");
//		else if(input>random_num)
//			printf("你的数字太大了！\n");
//		else
//		{
//			printf("恭喜猜对！\n");
//			Sleep(2000);
//			system("cls");   //完成后保持显示一会然后清屏
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
//		printf("输入操作要求(0/1):");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;  //每一个case和default最好先都加上break
//		case 0:
//			break;
//		default:
//			printf("输入错误，请重新输入。\n");
//			Sleep(500);
//			system("cls");
//			break;
//		}
//	}while (input); //input存在即input==1
//	return 0;
//}