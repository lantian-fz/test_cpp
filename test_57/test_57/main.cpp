#define _CRT_SECURE_NO_WARNINGS 1
//����ת��
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
//�������� :����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
//������� :Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
//���룺7 2
//�����111
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

void NSystem(string &s, int m, int n)
{
	int tmp = 0;
	bool flag = true;
	if (m == 0)//0���������ƻ���0
	{
		s.push_back('0');
		return;
	}
	while (m)
	{
		if (m<0)
		{
			m = -m;//�Ƚ�m��������������
			flag = false;
		}
		if (m%n > 9)
			tmp = (m%n - 10 + 'A');//�ο�16���ƣ�����9����ĸ��ʾ
		else
			tmp = m%n + '0';
		s.push_back(tmp);
		m /= n;
	}
	if (flag==false)
		s.push_back('-');

	reverse(s.begin(), s.end());

	//deque<char> dq;
	//int tmp = 0;
	//bool flag = true;//���mΪ����
	//if (m == 0)//0���������ƻ���0
	//{
	//	s.push_back('0');
	//	return;
	//}
	//while (m)
	//{
	//	if (m<0)
	//	{
	//		m = -m;//�Ƚ�m��������������
	//		flag = false;
	//	}
	//	if (m%n > 9)
	//		tmp = (m%n - 10 + 'A');//�ο�16���ƣ�����9����ĸ��ʾ
	//	else
	//		tmp = m%n + '0';
	//	dq.push_back(tmp);
	//	m /= n;
	//}
	//if (flag==false)
	//	dq.push_back('-');

	//while (!dq.empty())
	//{
	//	s.push_back(dq.back());
	//	dq.pop_back();
	//}
}

int main()
{
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;
	string s;
	NSystem(s, m, n);

	cout << s << endl;

	return 0;
}