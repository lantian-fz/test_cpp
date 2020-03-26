#define _CRT_SECURE_NO_WARNINGS 1
//找出字符串中第一个只出现一次的字符
//输入描述 :输入一个非空字符串
//输出描述 :输出第一个只出现一次的字符，如果不存在输出 - 1
//输入:asdfasdfo
//输出:o
#include <iostream>
#include <string>
using namespace std;
void fun(string &str)
{
	int arr[255] = { 0 };
	for (size_t i = 0; i<str.size(); i++)
	{
		arr[str[i]]++;
	}
	for (size_t i = 0; i<str.size(); i++)
	{
		if (arr[str[i]] == 1)
		{
			cout << str[i] << endl;
			return;
		}
	}
	cout << "-1" << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
		fun(str);
	return 0;
}