#define _CRT_SECURE_NO_WARNINGS 1
//����-�ַ������
//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
//����: num1 = "2", num2 = "3"           ���: "6"
//
//����: num1 = "123", num2 = "456"       ���: "56088"
//˵����
//num1 �� num2 �ĳ���С��110��
//num1 �� num2 ֻ�������� 0-9��
//num1 �� num2 �������㿪ͷ������������ 0 ����
//����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������

//˼·��
//			1   2   3
//		��  4   5   6
//����������������������������������������
//			6   12  18
//		5   10  15
//	4   8   12
//����������������������������������������
//	4   13  28  27  18
//���� c[i + 1] += c[i] / 10, c[i] %= 10, �ӵ�λ��ʼ��
//step 0 : 4   13  28  27  18
//step 1 : 4   13  28  28  8
//step 2 : 4   13  30  8   8
//step 3 : 4   16  0   8   8
//step 4 : 5   6   0   8   8
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) 
{
	string ret;
	vector<int> a, b, c;
	c.resize(num1.size() + num2.size() - 1);
	for (int i = num1.size() - 1; i >= 0; i--)
		a.push_back(num1[i] - '0');
	for (int i = num2.size() - 1; i >= 0; i--)
		b.push_back(num2[i] - '0');

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	}

	int k = 0;
	for (int i = 0; i < c.size(); i++)
	{
		k += c[i];
		char ch = k % 10 + '0';
		ret = ch + ret;
		k /= 10;
	}

	while (k)
	{
		char ch = k % 10 + '0';
		ret = ch + ret;
		k /= 10;
	}
	while (ret.size() > 1 && ret[0] == '0')
		ret.erase(ret.begin());
	return ret;
}

void main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << multiply(s1, s2) << endl;
}