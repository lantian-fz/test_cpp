#define _CRT_SECURE_NO_WARNINGS 1
//���ظ��ַ���Ӵ�
//����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//��������:�����ַ���(����<=100000)
//�������:�������ظ��ַ�����Ӵ�����
//ʾ��1:����:abcabcbb     ���:3
//˵��:��Ϊ���ظ��ַ�����Ӵ���"abc"�������䳤��Ϊ 3��
//ʾ��2:����:bbbbb:���:1
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int f[256] = { 0 };
	int x = 0;
	string s;
	cin >> s;
	int i = 0;
	for (int j = 0; j < s.size(); j++)
	{
		f[s[j]]++;
		while (i < j && f[s[j]] > 1)
		{
			f[s[i]]--;
			i++;
		}
		x = max(x, j - i + 1);
	}
	cout << x << endl;
	return 0;
}