#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ����
//��һ��N��С������, �������������1��N֮��, ��Щ���ֳ���2��, ��Щ���ֳ���1��.���ҳ����г���2�ε�����.
//��������
//ÿ���������һ������������ÿ�����������İ���N������ ��1 <= N <= 100��������������ݣ���֤��ͬ���ֲ������3���Լ�3������
//��Ŀ��֤��������Ϸ���
//�������
//���һ�����У��������г��ֹ�2�ε�����
//����ʾ��
//1 2 5 2 3 4 8 5 4
//���ʾ��
//2 5 4

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���ַ���ת��Ϊ����
void StrNum(string s,vector<int>& arr)
{
	auto it = s.begin();
	while (it != s.end())
	{
		string num = "";
		while (it != s.end() && (*it != ' '))
		{
			num += *it;
			it++;
		}
		int n = atoi(num.c_str());//�ַ���ת����
		arr.push_back(n);
		if (it != s.end())
			it++;
	}
}

//�ҵ����ֹ����ε�����
vector<int> fun(vector<int> arr)
{
	vector<int> num(arr.size() + 1, 0);
	for (int i = 0; i < arr.size(); i++)
		num[arr[i]]++;
	vector<int> ret;
	for (int i = 0; i < arr.size(); i++)
	{
		if (num[arr[i]] == 2)
		{
			ret.push_back(arr[i]);
			num[arr[i]] = 0;
		}
	}
	return ret;
}

void main()
{
	string s;
	while (getline(cin, s))
	{
		vector<int> arr;
		StrNum(s, arr);

		vector<int> tmp = fun(arr);
		cout << tmp[0];
		for (int i = 1; i < tmp.size();i++)
			cout << " " << tmp[i];
		cout << endl;
	}
}