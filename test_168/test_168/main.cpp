#define _CRT_SECURE_NO_WARNINGS 1
//����-451.�����ַ�����Ƶ������
//����һ���ַ������뽫�ַ�������ַ����ճ��ֵ�Ƶ�ʽ������С�
//ʾ�� 1:����:"tree"          ���:"eert"
//����:'e'�������Σ�'r'��'t'��ֻ����һ�Ρ����'e'���������'r'��'t'֮ǰ�����⣬"eetr"Ҳ��һ����Ч�Ĵ𰸡�
//
//ʾ�� 2:����:"cccaaa"        ���:"cccaaa"
//����:'c'��'a'���������Ρ����⣬"aaaccc"Ҳ����Ч�Ĵ𰸡�ע��"cacaca"�ǲ���ȷ�ģ���Ϊ��ͬ����ĸ�������һ��
//
//ʾ�� 3:����:"Aabb"          ���:"bbAa"
//����:���⣬"bbaA"Ҳ��һ����Ч�Ĵ𰸣���"Aabb"�ǲ���ȷ�ġ�ע��'A'��'a'����Ϊ�����ֲ�ͬ���ַ���

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�����������ǽ���������������ڲ���Ҫ��static���������ⲻ�ü�
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