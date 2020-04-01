#define _CRT_SECURE_NO_WARNINGS 1
//������
//���������ߣ������ж�һ���ܲ������һ�������Ρ�
//�������� :��������������ݣ�ÿ�����ݰ�������������a��b��c��1��a, b, c��10^100����
//������� :��Ӧÿһ�����ݣ�������������һ�������Σ��������Yes�������������No����
//���룺1 2 3
//      2 2 2
//�����No
//      Yes

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//���������
string Add(string str1, string str2)
{
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	while (str1.size() != str2.size())//�������ַ����ȳ��������Ĳ�0
	{
		if (str1.size() < str2.size())
			str1 += '0';
		else if (str1.size()>str2.size())
			str2 += '0';
	}
	string ret;
	int x = 0;
	int count = 0;//��λ

	for (size_t i = 0; i < str1.size(); i++)
	{
		count = str1[i] + str2[i] - '0' - '0' + x;
		if (count >= 10)
		{
			ret.push_back(count - 10 + '0');
			x = 1;
		}
		else
		{
			ret.push_back(count + '0');
			x = 0;
		}
	}
	if (x > 0)
		ret.push_back('1');
	reverse(ret.begin(), ret.end());
	return ret;
}
bool Compare(string str1, string str2)//����֮�ʹ��ڵ�����ʱ����true
{
	//str1Ϊ����֮�ͣ�str2Ϊ������
	if (str1.size() < str2.size())
		return false;
	else if (str1.size()>str2.size())
		return true;
	else
		return str1 > str2;
}

int main()
{
	//���������֮�ͣ�����������ȱȽ�
	//��������ȱȽϳ��ȣ�������ͬ������λ��ʼ�Ƚ�
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3)
	{
		if (Compare(Add(s1, s2), s3) && Compare(Add(s1, s3), s2) && Compare(Add(s2, s3), s1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}