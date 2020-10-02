#define _CRT_SECURE_NO_WARNINGS 1
//两句话中的不常见单词
//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//返回所有不常用单词的列表。您可以按任何顺序返回列表。
//
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet", "sour"]
//
//输入：A = "apple apple", B = "banana"
//输出：["banana"]
//
//提示：
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。

#include<iostream>
#include<string>
#include <vector>
#include<unordered_map>
#include<map>
using namespace std;

void funstrtok(string &s, unordered_map<string, int>& mp)
{
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == ' ')
			i++;
		else
		{
			int count = i;
			while (s[i] != '\0'&&s[i] != ' ')
				i++;
			string tmp = s.substr(count, i - count);
			mp[tmp]++;
		}
	}
}

vector<string> uncommonFromSentences(string A, string B) 
{
	vector<string> ret;
	unordered_map<string,int> mp;
	if (A.empty() && B.empty())
		return ret;

	funstrtok(A, mp);
	funstrtok(B, mp);

	for (auto &e : mp)
	{
		if (e.second < 2)
			ret.push_back(e.first);
	}
	return ret;
}
void main()
{
	string s1 = "apple apple";
	string s2 = "banana";
	vector<string> ret = uncommonFromSentences(s1, s2);
	for (auto& e : ret)
		cout << e << " ";
	cout << endl;
}

//void main()
//{
//	pair<int, string> arr[] = {
//		{ 101, "zzzz" },
//		{ 105, "aaaaaa" },
//		{ 104, "ssssss" },
//		{ 105, "ttttt" },
//		{ 103, "zzzzzz" },
//		{ 105, "aaaaaa" },
//		{ 105, "aaaaaa" },
//		{ 105, "cccc" }
//	};
//	unordered_map<int, string> unmap;
//	unordered_multimap<int, string> un_mumap;
//	map<int, string> mp;
//	multimap<int, string> mump;
//	for (auto e : arr)
//	{
//		unmap.insert(e);
//		un_mumap.insert(e);
//		mp.insert(e);
//		mump.insert(e);
//	}
//
//	for (const auto& e : unmap)
//		cout << e.first << " : " << e.second << endl;
//	cout << "---------------" << endl;
//	for (const auto& e : un_mumap)
//		cout << e.first << " : " << e.second << endl;
//	cout << "---------------" << endl;
//	for (const auto& e : mp)
//		cout << e.first << " : " << e.second << endl;
//	cout << "---------------" << endl;
//	for (const auto& e : mump)
//		cout << e.first << " : " << e.second << endl;
//}

//bool fun2(int x)
//{
//	if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
//		return false;
//	return true;
//}
//
//int fun1(int n)
//{
//	int ret = 0;
//	int mid = n / 2;
//	int i = 2;
//	while (i < mid)
//	{
//		if (n%i == 0)
//		{
//			if (fun2(i))
//				ret++;
//			if (fun2(n / i))
//				ret++;
//		}
//		i++;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//		cout << fun1(n) << endl;
//
//	return 0;
//}