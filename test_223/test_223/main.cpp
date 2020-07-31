#define _CRT_SECURE_NO_WARNINGS 1
//力扣-字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//输入: num1 = "2", num2 = "3"           输出: "6"
//
//输入: num1 = "123", num2 = "456"       输出: "56088"
//说明：
//num1 和 num2 的长度小于110。
//num1 和 num2 只包含数字 0-9。
//num1 和 num2 均不以零开头，除非是数字 0 本身。
//不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

//思路：
//			1   2   3
//		乘  4   5   6
//————————————————————
//			6   12  18
//		5   10  15
//	4   8   12
//————————————————————
//	4   13  28  27  18
//整理： c[i + 1] += c[i] / 10, c[i] %= 10, 从低位开始。
//step 0 : 4   13  28  27  18
//step 1 : 4   13  28  28  8
//step 2 : 4   13  30  8   8
//step 3 : 4   16  0   8   8
//step 4 : 5   6   0   8   8
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) 
{
	string ret;
	vector<int> a, b, c;
	c.resize(num1.size() + num2.size() - 1);
	for (int i = num1.size() - 1; i >= 0; i--)
		a.push_back(num1[i] - '0');
	for (int i = num2.size() - 1; i >= 0; i--)
		b.push_back(num2[i] - '0');

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	}

	int k = 0;
	for (int i = 0; i < c.size(); i++)
	{
		k += c[i];
		char ch = k % 10 + '0';
		ret = ch + ret;
		k /= 10;
	}

	while (k)
	{
		char ch = k % 10 + '0';
		ret = ch + ret;
		k /= 10;
	}
	while (ret.size() > 1 && ret[0] == '0')
		ret.erase(ret.begin());
	return ret;
}

void main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << multiply(s1, s2) << endl;
}