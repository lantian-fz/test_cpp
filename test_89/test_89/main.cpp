#define _CRT_SECURE_NO_WARNINGS 1
//�ַ�����ת
//д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
//�������� :����N���ַ�
//������� :������ַ�����ת����ַ���
//���룺abcd
//�����dcba
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}