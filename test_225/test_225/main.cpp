#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-Ѱ���ַ���
//����֪���Ƚ������ַ����Ƿ���ȿ����ú���strcmp����������ַ�������򷵻�0�����򷵻�����ֵ��
//��ô�����Ѱ��һ���ַ����Ƿ�����һ���ַ����г��ֹ������ҳ��ֹ����ٴ��أ�
//���磺�����ַ����ֱ�Ϊ��abababa��aba, ��ôaba��abababa�г��ֵĴ���Ϊ3��
//
//�������� :����������У��ڶ���ΪҪ�ڵ�һ�в��ҵ��ַ������ַ������ܰ�����ĸ�����֡������Լ��ո�
//������� :���Ϊһ�����֣���ʾ�ڶ����ַ����ڵ�һ�г��ֵĴ�����
//����
//i miss you!
//you
//���
//1
//
//����
//ababcababca
//ababca
//���
//2

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	while (getline(cin, s1), getline(cin, s2))
	{
		int count = 0;
		int pos = 0, index = 0;

		while (1)
		{
			index = s1.find(s2,pos);
			if (index == s1.npos)
				break;
			count++;
			pos = index;
			pos++;
		}
		cout << count << endl;
	}
}