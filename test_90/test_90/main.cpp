#define _CRT_SECURE_NO_WARNINGS 1
//公共字串计算
//计算两个字符串的最大公共字串的长度，字符不区分大小写
//int getCommonStrLength(char * pFirstStr, char * pSecondStr);
//输入描述 :输入两个字符串
//输出描述 :输出一个整数
//输入:asdfas werasdfaswer
//输出:6
#include <iostream>
#include <string>
using namespace std;

void getCommonStrLength(string &s1, string &s2)
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
	cout << str.size() << endl;
}

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2)
		getCommonStrLength(s1, s2);

	return 0;
}