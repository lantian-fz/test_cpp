#define _CRT_SECURE_NO_WARNINGS 1
//查找两个字符串a, b中的最长公共子串
//查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
//输入描述 :输入两个字符串
//输出描述 :返回重复出现的字符
//输入: abcdefghijklmnop
//      abcsafjklmnopqrstuvw
//输出: jklmnop
#include <iostream>
#include <string>
using namespace std;

void findMaxCommonStr(string &s1, string &s2)
{
	if (s1.size() > s2.size())
		swap(s1, s2);
	string str;
	for (size_t i = 0; i < s1.size(); i++)
	{
		for (size_t j = i; j < s1.size(); j++)
		{
			string tmp = s1.substr(i, j - i + 1);
			int pos = s2.find(tmp);
			if (pos < 0)
				break;
			else if (str.size() < tmp.size())
				str = tmp;
		}
	}
	cout << str << endl;
}

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2)
		findMaxCommonStr(s1, s2);

	return 0;
}