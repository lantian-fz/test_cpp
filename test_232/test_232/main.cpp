#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��һ��ֻ����һ�ε��ַ�
//��һ���ַ���(0 <= �ַ������� <= 10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
//����������λ��, ���û���򷵻� - 1����Ҫ���ִ�Сд��.����0��ʼ������

#include <iostream>
#include <string>
using namespace std;

int FirstNotRepeatingChar(string str) 
{
	int arr[58] = { 0 };
	for (int i = 0; i < str.size(); i++)
		arr[str[i] - 65]++;
	for (int i = 0; i < 58; i++)
	{
		if (arr[str[i] - 65] == 1)
			return i;
	}
	return -1;
}

void main()
{
	string s;
	while (cin >> s)
		cout << FirstNotRepeatingChar(s) << endl;
}