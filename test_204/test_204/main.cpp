#define _CRT_SECURE_NO_WARNINGS 1
//����-��ӡ��1������nλ��-��ָoffer-12
//�������� n����˳���ӡ���� 1 ������ n λʮ��������
//�������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
//����: n = 1
//��� : [1, 2, 3, 4, 5, 6, 7, 8, 9]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//��򵥵ķ�������û�п��ǵ���������
vector<int> printNumbers_1(int n) 
{
	vector<int> arr;
	int x = (int)pow(10, n) - 1;
	if (n <= 0)
		return arr;
	for (int i = 1; i <= x; i++)
		arr.push_back(i);
	return arr;
}

//�����������
bool Increment(string &s)
{
	bool flag = false;
	int x = 0;
	int len = s.size();
	for (int i = len - 1; i >= 0; i--)
	{
		int n = s[i] - '0' + x;
		if (i == len - 1)
			n++;
		if (n >= 10)
		{
			if (i == 0)
				flag = true;
			else
			{
				n -= 10;
				x = 1;
				s[i] = '0' + n;
			}
		}
		else
		{
			s[i] = '0' + n;
			break;
		}
	}
	return flag;
}

void Print(string s)
{
	string ss = "";
	bool flag = true;
	auto it = s.begin();
	while (it != s.end())
	{
		if (flag&&*it != '0')
			flag = false;
		if (!flag)
		{
			ss += *it;
		}
		it++;
	}
	cout << ss << " ";
}

void printNumbers_2(int n)
{
	if (n <= 0)
		return;
	string s(n, '0');
	while (!Increment(s))
		Print(s);
	cout << endl;
}

void main()
{
	int n = 0;
	while (cin >> n)
	{
		printNumbers_2(n);
		//vector<int> &p = printNumbers_1(n);
		//for (auto e : p)
		//	cout << e << " ";
		//cout << endl;
	}
}