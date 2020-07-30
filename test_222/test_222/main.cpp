#define _CRT_SECURE_NO_WARNINGS 1
//力扣-反转字符串中的单词 III
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//输入 : "Let's take LeetCode contest"
//输出 : "s'teL ekat edoCteeL tsetnoc"
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
	if (s.empty() || s.size() == 1)
		return s;
	int pos = 0;
	int index = 0;
	string ret;
	while (index != s.npos)
	{
		index = s.find(' ', pos);
		if (index == s.npos)
			break;
		string tmp(s.begin() + pos, s.begin() + index);
		reverse(tmp.begin(), tmp.end());
		ret += tmp + ' ';
		pos = index + 1;
	}
	string tmp(s.begin() + pos, s.end());
	reverse(tmp.begin(), tmp.end());
	ret += tmp;
	return ret;
}

//原地翻转
string reverseWords_2(string s)
{
	if (s.empty() || s.size() == 1)
		return s;
	int len = s.size();
	int left = 0, right = 0;
	while (right < len)
	{
		while (right < len&&s[right] != ' ')
			right++;
		int n = right-- + 1;//right退回空格前
		while (left < right)
			swap(s[left++], s[right--]);
		left = n;
		right = n;
	}
	return s;
}

void main()
{
	string s = "Let's take LeetCode contest";
	cout << reverseWords_2(s) << endl;
}