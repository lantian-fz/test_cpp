#define _CRT_SECURE_NO_WARNINGS 1
//输入两个字符串，从第一个字符串中删除第二个字符串中所有的字符。
//例如：输入"They are students."和"aeiou"，则删除之后的第一个字符串变成"Thy r stdnts."
#include <iostream>
#include <string>
using namespace std;

string& KnockoutChar(string &s1, string &s2)
{
	int arr[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
		arr[s2[i]] = 1;
	for (int i = 0; i < s1.size(); i++)
	{
		if (arr[s1[i]] == 1)
		{
			auto pos = s1.begin() + i;
			s1.erase(pos);
			i--;
		}
	}
	return s1;
}

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << KnockoutChar(s1, s2) << endl;
	return 0;
}