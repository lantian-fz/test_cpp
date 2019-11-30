#define _CRT_SECURE_NO_WARNINGS 1
//给定两个二进制字符串，返回他们的和（用二进制表示）。
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1 :
//输入 : a = "11", b = "1"
//输出 : "100"
//示例 2 :
//输入 : a = "1010", b = "1011"
//输出 : "10101"

#include <iostream>
#include <string>
using namespace std;

void Reverse(string &str)
{
	int i = 0;
	int j = str.size() - 1;
	while (i < j)
	{
		char tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
}

string AddBinAry(string a, string b)
{
	string sum;
	//逆置a,b
	Reverse(a);
	Reverse(b);
	//使a,b的长度相等，不等的用0来补充
	if (a.size() >= b.size())
		b.resize(a.size(), '0');
	else
		a.resize(b.size(), '0');
	sum.resize(a.size());
	//相加
	int y = 0;//进位
	for (size_t i = 0; i < a.size(); i++)
	{
		int x = a[i] + b[i] + y - '0' - '0';
		if (x >= 2)
		{
			y = 1;
			if (x == 3)
				sum[i] = '1';
			else
				sum[i] = '0';
			if (i == a.size() - 1)
			{
				i++;
				sum.resize(a.size() + 1);
				sum[i] = '1';
			}
		}
		else
		{
			if (x == 0)
			{
				sum[i] = '0';
			}
			else
				sum[i] = '1';
			y = 0;
		}
	}
	Reverse(sum);
	return sum;
}

int main()
{
	string a;
	string b;
	cin >> a;
	cin >> b;
	cout << AddBinAry(a, b) << endl;
	return 0;
}