#define _CRT_SECURE_NO_WARNINGS 1
//����-67. ���������
//���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
//����Ϊ �ǿ� �ַ�����ֻ�������� 1 �� 0��
//����: a = "11", b = "1"
//���: "100"
//
//����: a = "1010", b = "1011"
//���: "10101"
//��ʾ��
//ÿ���ַ��������ַ� '0' �� '1' ��ɡ�
//1 <= a.length, b.length <= 10^4
//�ַ���������� "0" ���Ͷ�����ǰ���㡣

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) 
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() > b.size())
		b.resize(a.size(), '0');
	else
		a.resize(b.size(), '0');
	string s;
	int count = 0;//��λ
	for (size_t i = 0; i < a.size(); i++)
	{
		count += a[i] + b[i] - '0' - '0';
		if (count >= 2)
		{
			s.push_back(count - 2 + '0');
			count = 1;
		}
		else
		{
			s.push_back(count + '0');
			count = 0;
		}
	}
	if (count > 0)
		s.push_back('1');
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	string a, b;
	while (cin >> a >> b)
		cout << addBinary(a, b) << endl;

	return 0;
}