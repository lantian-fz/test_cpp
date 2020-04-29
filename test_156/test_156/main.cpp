#define _CRT_SECURE_NO_WARNINGS 1
//力扣-67. 二进制求和
//给你两个二进制字符串，返回它们的和（用二进制表示）。
//输入为 非空 字符串且只包含数字 1 和 0。
//输入: a = "11", b = "1"
//输出: "100"
//
//输入: a = "1010", b = "1011"
//输出: "10101"
//提示：
//每个字符串仅由字符 '0' 或 '1' 组成。
//1 <= a.length, b.length <= 10^4
//字符串如果不是 "0" ，就都不含前导零。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) 
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() > b.size())
		b.resize(a.size(), '0');
	else
		a.resize(b.size(), '0');
	string s;
	int count = 0;//进位
	for (size_t i = 0; i < a.size(); i++)
	{
		count += a[i] + b[i] - '0' - '0';
		if (count >= 2)
		{
			s.push_back(count - 2 + '0');
			count = 1;
		}
		else
		{
			s.push_back(count + '0');
			count = 0;
		}
	}
	if (count > 0)
		s.push_back('1');
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	string a, b;
	while (cin >> a >> b)
		cout << addBinary(a, b) << endl;

	return 0;
}