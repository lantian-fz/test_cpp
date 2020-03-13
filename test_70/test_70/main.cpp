#define _CRT_SECURE_NO_WARNINGS 1
//�����������
//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b��
//�����һ���㷨�����a��b�������������ȵı�š�
//��������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�
//����������2��3
//���أ�1
#include <iostream>
#include <math.h>
using namespace std;

int getLCA_1(int a, int b) 
{
	while (a != b)
	{
		if (a > b)
			a /= 2;
		else if (a < b)
			b /= 2;
	}
	return a;
}

int getLCA_2(int a, int b)
{
	if (a>b)
		return getLCA_2(a / 2, b);
	else if (a < b)
		return getLCA_2(a, b / 2);
	else
		return a;
}

int main()
{
	int a = 0;
	int b = 0;
	cin>>a>>b;
	cout << getLCA_1(a, b) << endl;
	cout << getLCA_2(a, b) << endl;

	return 0;
}