#define _CRT_SECURE_NO_WARNINGS 1
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing. like I
//�������� :ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//������� :�����������֮����ַ���, �Կո�ָ�
//����: I like beijing.
//���: beijing. like I
#include <iostream>
#include <string>
using namespace std;

string& Reverse(string &s)
{
	reverse(s.begin(), s.end());
	int n = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (s[i + 1] == ' ')
			i++;
		if (s[i] == ' ')//�п����������ո�
		{
			if (i == s.size() - 1)
			{
				reverse(s.begin() + n, s.begin() + i + 1);
				break;
			}
			reverse(s.begin() + n, s.begin() + i);
			n = i + 1;
		}
	}

	return s;
}

int main()
{
	string s;
	getline(cin, s);
	cout << Reverse(s) << endl;

	return 0;
}