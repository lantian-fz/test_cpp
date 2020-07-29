#define _CRT_SECURE_NO_WARNINGS 1
//力扣-字符串相加
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//注意：
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0 - 9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) 
{
	string ret;
	int n = 0;
	int i = num1.size() - 1, j = num2.size() - 1;
	
	while (i >= 0 || j >= 0 || n)
	{
		if (i >= 0)
			n += num1[i--] - '0';
		if (j >= 0)
			n += num2[j--] - '0';
		ret.push_back(n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << addStrings(s1, s2) << endl;
}