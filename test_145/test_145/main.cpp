#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-�����ֵܵ���
//������СдӢ����ĸ��ɣ����������ַ����ֵܵ��ʣ�����һ������X�����ͨ�����⽻����������ĸ��λ�õõ���ͬ
//�ĵ���Y����ô����Y��X���ֵܵ��ʡ�������bca��abc���ֵܵ��ʣ�abc��abc����ͬ���ʣ������ֵܵ���
//0<=�ֵ����������ʸ���<=100    1<=����������ĸ��<=50
//�������� :�������ֵ��е��ʵĸ���n��������n��������Ϊ�ֵ䵥�ʡ�
//	        ������һ�����ʣ����������ֵ����ֵܵ��ʵĸ���m
//          ����������k
//������� :�������룬������ҵ����ֵܵ��ʵĸ���m
//          Ȼ��������ҵ����ֵܵ��ʵĵ�k�����ʡ�
//����
//3 abc bca cab abc 1
//���
//2 
//bca
//ע�⣺���ֺ��ַ�������ռһ�У���Ҫ�жϱ߽���������û��ָ����ŵ��ֵ�ʱ��������ַ���
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
		int hash1[26] = { 0 };//��¼s����ĸ�����������ں���Ƚ�
		for (size_t i = 0; i < s.size(); i++)
			hash1[s[i] - 'a']++;
		int k = 0;
		cin >> k;
		int count = 0;//��������ͳ���ֵܵ��ʸ���
		string tmp;//��¼���ҵ����ֵܵ��ʵĵ�k������
		sort(arr.begin(), arr.end());
		for (size_t i = 0; i < arr.size(); i++)
		{
			if (arr[i].size() == s.size())
			{
				if (arr[i] == s)//�����ȣ������ֵܵ���
					continue;
				int hash2[26] = { 0 };
				for (size_t j = 0; j < s.size(); j++)
					hash2[arr[i][j] - 'a']++;
				int flag = 1;//1��ʾΪ�ֵܵ��ʣ�0��ʾ�����ֵܵ���
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
		if (k > count)//��k>�ֵܵ��ʸ���ʱֻ����ֵܵ��ʸ���
			cout << count << endl;
		else
			cout << count << endl << tmp << endl;//���Ϊ����
	}

	return 0;
}