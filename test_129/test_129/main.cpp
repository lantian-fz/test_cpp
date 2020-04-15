#define _CRT_SECURE_NO_WARNINGS 1
//无重复字符最长子串
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//输入描述:输入字符串(长度<=100000)
//输出描述:不含有重复字符的最长子串长度
//示例1:输入:abcabcbb     输出:3
//说明:因为无重复字符的最长子串是"abc"，所以其长度为 3。
//示例2:输入:bbbbb:输出:1
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int f[256] = { 0 };
	int x = 0;
	string s;
	cin >> s;
	int i = 0;
	for (int j = 0; j < s.size(); j++)
	{
		f[s[j]]++;
		while (i < j && f[s[j]] > 1)
		{
			f[s[i]]--;
			i++;
		}
		x = max(x, j - i + 1);
	}
	cout << x << endl;
	return 0;
}