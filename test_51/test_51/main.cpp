#define _CRT_SECURE_NO_WARNINGS 1
//���������ַ������ӵ�һ���ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磺����"They are students."��"aeiou"����ɾ��֮��ĵ�һ���ַ������"Thy r stdnts."
#include <iostream>
#include <string>
using namespace std;

string& KnockoutChar(string &s1, string &s2)
{
	int arr[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
		arr[s2[i]] = 1;
	for (int i = 0; i < s1.size(); i++)
	{
		if (arr[s1[i]] == 1)
		{
			auto pos = s1.begin() + i;
			s1.erase(pos);
			i--;
		}
	}
	return s1;
}

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << KnockoutChar(s1, s2) << endl;
	return 0;
}