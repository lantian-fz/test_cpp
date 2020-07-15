#define _CRT_SECURE_NO_WARNINGS 1
//力扣-打印从1到最大的n位数-剑指offer-12
//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
//比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//输入: n = 1
//输出 : [1, 2, 3, 4, 5, 6, 7, 8, 9]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//最简单的方法，并没有考虑到大数问题
vector<int> printNumbers_1(int n) 
{
	vector<int> arr;
	int x = (int)pow(10, n) - 1;
	if (n <= 0)
		return arr;
	for (int i = 1; i <= x; i++)
		arr.push_back(i);
	return arr;
}

//解决大数问题
bool Increment(string &s)
{
	bool flag = false;
	int x = 0;
	int len = s.size();
	for (int i = len - 1; i >= 0; i--)
	{
		int n = s[i] - '0' + x;
		if (i == len - 1)
			n++;
		if (n >= 10)
		{
			if (i == 0)
				flag = true;
			else
			{
				n -= 10;
				x = 1;
				s[i] = '0' + n;
			}
		}
		else
		{
			s[i] = '0' + n;
			break;
		}
	}
	return flag;
}

void Print(string s)
{
	string ss = "";
	bool flag = true;
	auto it = s.begin();
	while (it != s.end())
	{
		if (flag&&*it != '0')
			flag = false;
		if (!flag)
		{
			ss += *it;
		}
		it++;
	}
	cout << ss << " ";
}

void printNumbers_2(int n)
{
	if (n <= 0)
		return;
	string s(n, '0');
	while (!Increment(s))
		Print(s);
	cout << endl;
}

void main()
{
	int n = 0;
	while (cin >> n)
	{
		printNumbers_2(n);
		//vector<int> &p = printNumbers_1(n);
		//for (auto e : p)
		//	cout << e << " ";
		//cout << endl;
	}
}