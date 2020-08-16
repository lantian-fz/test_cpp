#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�����ַ���
//����һ���������ַ�����S���������ѭ������Kλ������������
//���磬�ַ�����S = ��abcXYZdef��, Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//��ԭ�ַ�����Ϊ�����֣��ֲ���ת�������巭ת
string LeftRotateString(string str, int n) 
{
	if (str.empty() || n <= 0 || n > str.size() || str.size() == 1)
		return str;
	reverse(str.begin(), str.begin() + n);
	reverse(str.begin() + n, str.end());
	reverse(str.begin(), str.end());
	return str;
}

void main()
{
	string s;
	int n = 0;
	while (cin >> s >> n)
		cout << LeftRotateString(s, n) << endl;
}