#define _CRT_SECURE_NO_WARNINGS 1
//三角形
//给定三条边，请你判断一下能不能组成一个三角形。
//输入描述 :输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10^100）。
//输出描述 :对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No”。
//输入：1 2 3
//      2 2 2
//输出：No
//      Yes

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//大整数相加
string Add(string str1, string str2)
{
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	while (str1.size() != str2.size())//令两个字符串等长，不够的补0
	{
		if (str1.size() < str2.size())
			str1 += '0';
		else if (str1.size()>str2.size())
			str2 += '0';
	}
	string ret;
	int x = 0;
	int count = 0;//进位

	for (size_t i = 0; i < str1.size(); i++)
	{
		count = str1[i] + str2[i] - '0' - '0' + x;
		if (count >= 10)
		{
			ret.push_back(count - 10 + '0');
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
bool Compare(string str1, string str2)//两边之和大于第三边时返回true
{
	//str1为两边之和，str2为第三边
	if (str1.size() < str2.size())
		return false;
	else if (str1.size()>str2.size())
		return true;
	else
		return str1 > str2;
}

int main()
{
	//先求出两边之和，再与第三边先比较
	//与第三边先比较长度，长度相同则从最高位开始比较
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3)
	{
		if (Compare(Add(s1, s2), s3) && Compare(Add(s1, s3), s2) && Compare(Add(s2, s3), s1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}