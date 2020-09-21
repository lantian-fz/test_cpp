#define _CRT_SECURE_NO_WARNINGS 1
//ǰK����Ƶ����
//��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
//���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������
//
//����: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//���: ["i", "love"]
//����: "i" �� "love" Ϊ���ִ��������������ʣ���Ϊ2�Ρ�ע�⣬����ĸ˳�� "i" �� "love" ֮ǰ��
// 
//����: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
//���: ["the", "is", "sunny", "day"]
//����: "the", "is", "sunny" �� "day" �ǳ��ִ��������ĸ����ʣ�
//    ���ִ�������Ϊ 4, 3, 2 �� 1 �Ρ�
//
//ע�⣺�ٶ� k ��Ϊ��Чֵ�� 1 �� k �� ����Ԫ����������ĵ��ʾ���Сд��ĸ��ɡ�

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