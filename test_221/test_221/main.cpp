#define _CRT_SECURE_NO_WARNINGS 1
//����-��ת�ַ���2
//����һ���ַ��� s ��һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת��
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
//
//���� : s = "abcdefg", k = 2     ��� : "bacdfeg"

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseStr(string s, int k)
{
	if (s.empty() || k == 1)
		return s;
	int len = s.size();
	for (int i = 0; i < len; i += 2 * k)
	{
		if (len - i < 2 * k)//��ʣ���ַ�����2*k��ʱ��
		{
			if (len - i < k)//ʣ���ַ�ȫ����ת
				reverse(s.begin() + i, s.end());
			else
				reverse(s.begin() + i, s.begin() + i + k);//��תǰk���ַ�
			return s;
		}
		else
			reverse(s.begin() + i, s.begin() + i + k);
	}
	return s;
}
void main()
{
	string s = "abcdefg";
	cout << reverseStr(s, 2) << endl;
}