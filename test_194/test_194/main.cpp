#define _CRT_SECURE_NO_WARNINGS 1
//CCF201912-1 报数
//甲乙丙丁决定玩一个报数的游戏来打发时间。游戏规则为四个人从1开始轮流进行报数，但如果需要
//报出的数是7的倍数或含有数字7则直接跳过。此外大家约定，在总共报出n个数后(不计入被跳过的数)游戏结束。
//现在需要你来帮忙统计，游戏过程中每个人各自跳过了几次。
//
//输入格式：输入仅一行，包含一个正整数n，表示报出了多少个数后游戏结束
//输出格式：输出共四行，每行一个整数，依次表示甲乙丙丁四人在游戏过程中跳过的次数
//
//样例输入：20
//样例输出：
//2
//1
//1
//0
//
//样例解释：报数过程为：
//甲：1   乙：2  丙：3  丁：4
//甲：5   乙：6  丙：跳过  丁：8
//甲：9   乙：10  丙：11  丁：12
//甲：13   乙：跳过  丙：15  丁：16
//甲：跳过   乙：18  丙：19  丁：20
//甲：跳过   乙：22  丙：23  丁：24

#include <iostream>
using namespace std;

int fun(int n)
{
	if (n % 7 == 0)
		return 1;
	while (n)
	{
		if (n % 10 == 7)
			return 1;
		else
			n /= 10;
	}
	return 0;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int arr[4] = { 0 };
		int i = 1;
		int num = 1;

		while (i <= n)
		{
			if (fun(num) == 1)
				arr[(num - 1) % 4]++;
			else
				i++;
			num++;
		}
		for (int j = 0; j < 4; j++)
			cout << arr[j] << endl;
	}

	return 0;
}