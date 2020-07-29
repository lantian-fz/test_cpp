#define _CRT_SECURE_NO_WARNINGS 1
//力扣-验证回文串
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//输入: "A man, a plan, a canal: Panama"           输出: true
//
//输入: "race a car"                               输出: false

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) 
{
	if (s.empty())
		return true;
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		//先全部转换为大写
		if (s[i] >= 'a'&&s[i] <= 'z')
			s[i] -= 32;
		if (s[j] >= 'a'&&s[j] <= 'z')
			s[j] -= 32;
		if ((s[i]<'A' || s[i]>'Z') && (s[i]<'0' || s[i]>'9'))
		{
			i++;
			continue;
		}
		if ((s[j]<'A' || s[j]>'Z') && (s[j]<'0' || s[j]>'9'))
		{
			j--;
			continue;
		}
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool isPalindrome_2(string s)
{
	if (s.empty())
		return true;
	string str;
	for (auto i : s)
	{
		if (i >= 'a'&&i <= 'z')
			i -= 32;
		if (i >= 'A'&&i <= 'Z' || i >= '0'&&i <= '9')
			str.push_back(i);
	}
	string str2(str);
	reverse(str2.begin(), str2.end());
	if (strcmp(str.c_str(), str2.c_str()) == 0)
		return true;
	return false;
}

void main()
{
	string s = "ab2a";
	cout << isPalindrome_2(s) << endl;
}