#define _CRT_SECURE_NO_WARNINGS 1
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing. like I
//输入描述 :每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述 :依次输出倒置之后的字符串, 以空格分割
//输入: I like beijing.
//输出: beijing. like I
#include <iostream>
#include <string>
using namespace std;

string& Reverse(string &s)
{
	reverse(s.begin(), s.end());
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (s[i + 1] == ' ')
			i++;
		if (s[i] == ' ')//有可能有两个空格
		{
			if (i == s.size() - 1)
			{
				reverse(s.begin() + n, s.begin() + i + 1);
				break;
			}
			reverse(s.begin() + n, s.begin() + i);
			n = i + 1;
		}
	}

	return s;
}

int main()
{
	string s;
	getline(cin, s);
	cout << Reverse(s) << endl;

	return 0;
}