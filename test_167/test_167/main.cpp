#define _CRT_SECURE_NO_WARNINGS 1
//力扣-387.字符串中的第一个唯一字符
//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。
//案例 :s = "leetcode"           返回 0.
//      s = "loveleetcode",      返回 2.
//注意事项：您可以假定该字符串只包含小写字母。

#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) 
{
	int arr[256] = { 0 };
	for (size_t i = 0; i < s.size(); i++)
		arr[s[i]]++;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (arr[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string s;
	while (cin >> s)
		cout << firstUniqChar(s) << endl;

	return 0;
}