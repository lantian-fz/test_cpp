#define _CRT_SECURE_NO_WARNINGS 1
//力扣-451.根据字符出现频率排序
//给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
//示例 1:输入:"tree"          输出:"eert"
//解释:'e'出现两次，'r'和't'都只出现一次。因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
//
//示例 2:输入:"cccaaa"        输出:"cccaaa"
//解释:'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。注意"cacaca"是不正确的，因为相同的字母必须放在一起。
//
//示例 3:输入:"Aabb"          输出:"bbAa"
//解释:此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。注意'A'和'a'被认为是两种不同的字符。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//力扣里面若是将这个函数放在类内部需要加static，放在类外不用加
static bool Second(pair<int,int> &a, pair<int,int> &b)
{
	return a.second > b.second;
}

string frequencySort(string s) 
{
	vector<pair<int, int>> arr(256);
	string ret;
	for (size_t i = 0; i < s.size(); i++)
	{
		arr[s[i]].first = s[i];
		arr[s[i]].second++;
	}
	sort(arr.begin(), arr.end(), Second);
	for (int i = 0; arr[i].second != 0; i++)
	{
		string tmp(arr[i].second, (char)arr[i].first);
		ret += tmp;
	}

	return ret;
}

int main()
{
	string s;
	while (cin >> s)
		cout << frequencySort(s) << endl;

	return 0;
}