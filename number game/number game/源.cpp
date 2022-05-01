#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>

//int muti(int m)
//{
//	int i = 1;
//	int j = 1;
//	for (i = 1; i <= m; i++)
//		j = j * i;
//	return j;
// }
//
//int main()
//{
//	int a = 1;
//	int b = 0;
//	for (a = 1; a <= 3; a++)
//		b = b + muti(a);
//	printf("%d", b);
//	return 0;
//}


////二分查找，即折半查找
//#include<stdio.h>
//
//int main()
//{
//	int arr[10] = {7,8,9,10,11,12,16,18,19,20};
//	int k = 7;
//	//printf("请输入你想查找的数字：");
//	//scanf("%d", &k);
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("查找成功，下标为：%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("查找失败\n");
//
//	return 0;
//}

#include<stdio.h>
