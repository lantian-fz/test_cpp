#define _CRT_SECURE_NO_WARNINGS 1
//���м������ʵ���
//���ַ����е����е��ʽ��е��š�
//1��ÿ����������26����д��СдӢ����ĸ���ɣ�
//2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
//3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
//4��ÿ�������20����ĸ��
//�������� :����һ���Կո����ָ��ľ���
//������� :������ӵ�����
//����
//I am a student
//���
//student a am I

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string ret;
		auto it = s.begin();
		while (it != s.end())
		{
			string tmp;
			while (it != s.end() && (*it >= 'a'&&*it <= 'z' || *it >= 'A'&&*it <= 'Z'))
			{
				tmp += *it;
				it++;
			}
			while (it != s.end() && !(*it >= 'a'&&*it <= 'z' || *it >= 'A'&&*it <= 'Z'))
				it++;
			ret = ' ' + tmp + ret;
		}
		ret.erase(0, 1);
		cout << ret << endl;
	}

	return 0;
}