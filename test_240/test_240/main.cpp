#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-左旋字符串
//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S = ”abcXYZdef”, 要求输出循环左移3位后的结果，即“XYZdefabc”。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//将原字符串分为两部分，局部翻转后再整体翻转
string LeftRotateString(string str, int n) 
{
	if (str.empty() || n <= 0 || n > str.size() || str.size() == 1)
		return str;
	reverse(str.begin(), str.begin() + n);
	reverse(str.begin() + n, str.end());
	reverse(str.begin(), str.end());
	return str;
}

void main()
{
	string s;
	int n = 0;
	while (cin >> s >> n)
		cout << LeftRotateString(s, n) << endl;
}