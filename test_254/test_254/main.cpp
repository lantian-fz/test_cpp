#define _CRT_SECURE_NO_WARNINGS 1
//前K个高频单词
//给一非空的单词列表，返回前 k 个出现次数最多的单词。
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
//
//输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出: ["i", "love"]
//解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。注意，按字母顺序 "i" 在 "love" 之前。
// 
//输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
//输出: ["the", "is", "sunny", "day"]
//解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//    出现次数依次为 4, 3, 2 和 1 次。
//
//注意：假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。输入的单词均由小写字母组成。

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> x, pair<string, int> y)
{
	if (x.second != y.second)
		return x.second > y.second;
	else
		return x.first < y.first;
}

vector<string> topKFrequent(vector<string>& words, int k)
{
	unordered_map<string, int> hash;
	for (auto& e : words)
		hash[e]++;
	vector<pair<string, int>> tmp;
	for (auto e : hash)
		tmp.push_back(pair<string,int>(e.first,e.second));
	sort(tmp.begin(), tmp.end(), cmp);
	vector<string> ret;
	for (int i = 0; i < k; i++)
		ret.push_back(tmp[i].first);
	return ret;
}

void main()
{
	vector<string> arr = { "i", "love", "leetcode", "i", "love", "coding" };
	vector<string> ret = topKFrequent(arr, 2);
	for (auto e : ret)
		cout << e << " ";
	cout << endl;
}