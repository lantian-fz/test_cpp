#define _CRT_SECURE_NO_WARNINGS 1
//回文游戏
//时间限制：C / C++语言 1000MS；其他语言 3000MS
//内存限制：C / C++语言 65536KB；其他语言 589824KB
//题目描述：
//Cassidy和Eleanore是一对好朋友，她们经常会一起玩游戏。某一天她们玩了一个回文游戏。
//游戏规则是这样的：给出一个仅包含小写字母的字符串S，在每一个人的回合中，她们会进行两个操作：
//1. 尝试重新排列这个字符串，如果可以把这个字符串排列成回文字符串，则立即获胜。
//2. 否则，她们必须删掉字符串中的一个字符。
//已知，Cassidy先手，在两个人都采取最佳策略的情况下，谁可以获胜。
//输入
//输入第一行仅包含一个正整数t，表示数据组数，(t <= 10)
//接下来有t行，每行有一个字符串S，表示一组测试数据。(| S | <= 1000)
//输出
//对于每组数据输出一行，如果Cassidy获胜，则输出Cassidy，否则输出Eleanore
//样例输入
//2
//aba
//ab
//样例输出
//Cassidy
//Eleanore

#include <iostream>
#include <string>
using namespace std;

void fun(string &str)
{
	int arr[256] = { 0 };
	for (size_t i = 0; i < str.size(); i++)
		arr[str[i]]++;
	int n = 0;
	string s;
	while (1)
	{
		if (n % 2 == 0)
			s = "Cassidy";
		else
			s = "Eleanore";
		n++;
		int count = 0;
		int x = 0;
		for (int i = 0; i < 256; i++)
		{
			if (arr[i]%2==1)
			{
				count++;
				x = i;
			}
		}
		if (count == 1||count == 0)
		{
			cout << s << endl;
			return;
		}
		else
		{
			arr[x]--;
		}
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		while (n)
		{
			string str;
			cin >> str;
			fun(str);
			n--;
		}
	}

	return 0;
}