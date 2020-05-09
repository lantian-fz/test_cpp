#define _CRT_SECURE_NO_WARNINGS 1
//����-38.�������
//��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������ǰ�������£�
//1.     1
//2.     11         1 ������  "one 1"  ("һ��һ"), �� 11��
//3.     21         11 ������ "two 1s" ("����һ"��, �� 21��
//4.     1211       21 ������ "one 2", "one 1" ��"һ����", "һ��һ"), �� 1211��
//5.     111221
//����һ�������� n��1 �� n �� 30�������������еĵ� n �ע�⣺���������е�ÿһ���ʾΪһ���ַ�����
//ʾ�� 1:����: 1            ���: "1"        
//
//ʾ�� 2:
//����: 4
//���: "1211"
//���ͣ��� n = 3 ʱ�������� "21"������������ "2" �� "1" ���飬"2" ���Զ��� "12"��Ҳ���ǳ���Ƶ�� = 1 �� ֵ = 2��
//���� "1" ���Զ��� "11"�����Դ��� "12" �� "11" �����һ��Ҳ���� "1211"��

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string countAndSay(int n) 
{
	if (n == 1)
		return "1";
	string s = "1";
	//string tmp = s;
	for (int i = 1; i < n; i++)
	{
		string tmp;

		for (size_t j = 0; j < s.size(); j++)
		{
			int count = 0;
			int x = j;
			char t = s[j];
			while (s[j] == t)
			{
				count++;
				j++;
			}
			tmp += to_string(count) + t;
			if (j <= s.size() - 1)
				j = x + 1;
		}
		s = tmp;
	}


	return s;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << countAndSay(n) << endl;

	return 0;
}