#define _CRT_SECURE_NO_WARNINGS 1
//统计每个月兔子的总数
//有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，
//假如兔子都不死，问每个月的兔子总数为多少？
//public static int getTotalCount(int monthCount)
//{
//	return 0;
//}
//输入描述:输入int型表示month
//输出描述 :输出兔子总数int型
//输入: 9
//输出: 34
#include <iostream>
using namespace std;
//符合斐波那契数列
int getTotalCount(int month)
{
	if (month == 1 || month == 2)
		return 1;
	else
		return getTotalCount(month - 1) + getTotalCount(month - 2);
}

int getTotalCount2(int month)
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (month == 1 || month == 2)
		return 1;
	while (month > 2)
	{
		c = a + b;
		a = b;
		b = c;
		month--;
	}
	return c;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << getTotalCount2(n) << endl;
	return 0;
}