#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-����ת��
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
//�������� :����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
//������� :Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9�����Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
//����
//7 2
//���
//111

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void NSystem(int m, int n)
{
	int tmp = 0;
	string s;
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
	if (flag == false)
		s.push_back('-');

	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	int m = 0, n = 0;
	while (cin>>m>>n)
		NSystem(m, n);


	return 0;
}
