#define _CRT_SECURE_NO_WARNINGS 1
//有效的字母异位词
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//输入: s = "anagram", t = "nagaram"         输出: true
//
//输入: s = "rat", t = "car"                 输出: false
//说明: 你可以假设字符串只包含小写字母。

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isAnagram_1(string s, string t) 
{
	if (s.size()!=t.size())
		return false;
	if (s.empty())
		return true;
	unordered_map<char, int> mp1;
	unordered_map<char, int> mp2;
	for (int i = 0; i < s.size(); i++)
	{
		mp1[s[i]]++;
		mp2[t[i]]++;
	}
	for (auto& e : mp1)
	{
		if (e.second != mp2[e.first])
			return false;
	}
	return true;
}

bool isAnagram_2(string s, string t)
{
	if (s.size() != t.size())
		return false;
	if (s.empty())
		return true;
	int arr1[26] = { 0 };
	int arr2[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		arr1[s[i] - 'a']++;
		arr2[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

bool isAnagram_3(string s, string t)
{
	if (s.size() != t.size())
		return false;
	if (s.empty())
		return true;
	int arr[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i] - 'a']++;
		arr[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
			return false;
	}
	return true;
}
void main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << isAnagram_2(s1, s2) << endl;
}