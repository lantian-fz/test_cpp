#define _CRT_SECURE_NO_WARNINGS 1
//����-�ַ������
//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
//ע�⣺
//num1 ��num2 �ĳ��ȶ�С�� 5100.
//num1 ��num2 ��ֻ�������� 0 - 9.
//num1 ��num2 ���������κ�ǰ���㡣
//�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) 
{
	string ret;
	int n = 0;
	int i = num1.size() - 1, j = num2.size() - 1;
	
	while (i >= 0 || j >= 0 || n)
	{
		if (i >= 0)
			n += num1[i--] - '0';
		if (j >= 0)
			n += num2[j--] - '0';
		ret.push_back(n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << addStrings(s1, s2) << endl;
}