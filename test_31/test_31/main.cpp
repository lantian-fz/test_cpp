#define _CRT_SECURE_NO_WARNINGS 1
//ÿ����������һ���ַ������ַ�������󳤶�Ϊ100����ֻ������ĸ��
//������Ϊ�մ������ִ�Сд

//���������ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ������ϣ����ظ����ֲ��������ĸ�����
//�������� abcqweracb      ���  abcqwer
#include <iostream>
#include <string>
using namespace std;

string& Str(string& s)
{
	int arr[255] = { 0 };
	int sz = s.size();
	string tmp;
	tmp.resize(100);
	for (int i = 0; i<sz; i++)
	{
		arr[s[i]]++;
	}
	for (int i = 0; i<sz; i++)
	{
		if (arr[s[i]] != 0)
		{
			tmp[i] = s[i];
			if (arr[s[i]]>1)
				arr[s[i]] = 0;
		}
	}
	s = tmp;
	return s;
}

int main()
{
	string str;
	str.resize(100);
	cin >> str;
	cout << Str(str) << endl;


	return 0;
}