#define _CRT_SECURE_NO_WARNINGS 1
//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
//�������� :����һ���ǿ��ַ���
//������� :�����һ��ֻ����һ�ε��ַ��������������� - 1
//����:asdfasdfo
//���:o
#include <iostream>
#include <string>
using namespace std;
void fun(string &str)
{
	int arr[255] = { 0 };
	for (size_t i = 0; i<str.size(); i++)
	{
		arr[str[i]]++;
	}
	for (size_t i = 0; i<str.size(); i++)
	{
		if (arr[str[i]] == 1)
		{
			cout << str[i] << endl;
			return;
		}
	}
	cout << "-1" << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
		fun(str);
	return 0;
}