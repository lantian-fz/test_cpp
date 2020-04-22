#define _CRT_SECURE_NO_WARNINGS 1
//牛客-查找兄弟单词
//单词由小写英文字母组成，不含其它字符。兄弟单词：给定一个单词X，如果通过任意交换单词中字母的位置得到不同
//的单词Y，那么定义Y是X的兄弟单词。举例：bca是abc的兄弟单词；abc与abc是相同单词，不是兄弟单词
//0<=字典中所含单词个数<=100    1<=单词所含字母数<=50
//输入描述 :先输入字典中单词的个数n，再输入n个单词作为字典单词。
//	        再输入一个单词，查找其在字典中兄弟单词的个数m
//          再输入数字k
//输出描述 :根据输入，输出查找到的兄弟单词的个数m
//          然后输出查找到的兄弟单词的第k个单词。
//输入
//3 abc bca cab abc 1
//输出
//2 
//bca
//注意：数字和字符串各自占一行，还要判断边界条件，当没有指定序号的兄弟时，不输出字符串
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<string> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		string s;
		cin >> s;
		int hash1[26] = { 0 };//记录s的字母及个数，用于后面比较
		for (size_t i = 0; i < s.size(); i++)
			hash1[s[i] - 'a']++;
		int k = 0;
		cin >> k;
		int count = 0;//计数器，统计兄弟单词个数
		string tmp;//记录查找到的兄弟单词的第k个单词
		sort(arr.begin(), arr.end());
		for (size_t i = 0; i < arr.size(); i++)
		{
			if (arr[i].size() == s.size())
			{
				if (arr[i] == s)//如果相等，不是兄弟单词
					continue;
				int hash2[26] = { 0 };
				for (size_t j = 0; j < s.size(); j++)
					hash2[arr[i][j] - 'a']++;
				int flag = 1;//1表示为兄弟单词，0表示不是兄弟单词
				for (int j = 0; j < 26; j++)
				{
					if (hash1[j] != hash2[j])
					{
						flag = 0;
						break;
					}
				}
				if (flag)
					count++;
				else
					continue;
				if (count == k)
					tmp = arr[i];
			}
		}
		if (k > count)//当k>兄弟单词个数时只输出兄弟单词个数
			cout << count << endl;
		else
			cout << count << endl << tmp << endl;//输出为两行
	}

	return 0;
}