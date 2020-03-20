#define _CRT_SECURE_NO_WARNINGS 1
//超长正整数相加
//请设计一个算法完成两个超长正整数的加法。
//public String AddLongInteger(String addend, String augend)
//{
//	
//	return null;
//}
//输入描述:输入两个字符串数字
//输出描述 :输出相加后的结果，string型
//输入:99999999999999999999999999999999999999999999999999 1
//输出:100000000000000000000000000000000000000000000000000
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string AddLongInteger(string &s1, string &s2)
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string ret;
	while (s1.size() != s2.size())
	{
		if (s1.size() < s2.size())
			s1 += '0';
		else if (s1.size()>s2.size())
			s2 += '0';
	}
	int x = 0;
	int count = 0;//进位

	for (size_t i = 0; i < s1.size(); i++)
	{
		count = s1[i] + s2[i] - '0' - '0' + x;
		if (count >= 10)
		{
			ret.push_back(count-10 + '0');
			x = 1;
		}
		else
		{
			ret.push_back(count + '0');
			x = 0;
		}
	}
	if (x > 0)
		ret.push_back('1');
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << AddLongInteger(s1, s2) << endl;
	return 0;
}