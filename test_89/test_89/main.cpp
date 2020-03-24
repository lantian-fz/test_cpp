#define _CRT_SECURE_NO_WARNINGS 1
//字符串反转
//写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
//输入描述 :输入N个字符
//输出描述 :输出该字符串反转后的字符串
//输入：abcd
//输出：dcba
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}