#define _CRT_SECURE_NO_WARNINGS 1
//�ַ���ͨ���
//�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��ʵ������2��ͨ�����
//      *��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ��
//      ����ƥ��1���ַ�
//�������� :������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���
//������� :����ƥ��Ľ������ȷ���true���������false
//����: te?t*.*
//      txt12.xls
//���: false
#include <iostream>
#include <string>
using namespace std;
//ţ��ͨ����ȫ����������
//��֪���ǲ������������������������������⣬*����ƥ�� 0���ַ������ҵ����ҵĴ�������������
//abcde*ef
//abcdeef
//���н��Ϊ��false
//��Ӧ����true��

bool fun(string &s1, string &s2)
{
	int i = 0;//ͨ����ַ����±�
	int j = 0;//ƥ���ַ����±�
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j] || s1[i]=='?')
		{
			i++;
			j++;
			continue;
		}
		else if (s1[i] == '*')
		{
			i++;
			if (s1[i] == '\0')
				return true;
			while (s1[i] == '?')
				i++;
			int index = s2.find(s1[i], j+1);//��bug��*ƥ��0���ַ�ʱabcde*ef abcdeef
			if (index == -1)
				return false;
			else
				j = index;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (fun(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}