#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ַ���str������ַ���str�е�����������ִ�
//�������� :�������������1������������һ���ַ���str�����Ȳ�����255��
//������� :��һ�������str��������������ִ���
//����:abcd12345ed125ss123456789
//���:123456789
#include <iostream>
#include <string>
using namespace std;

string LongNumChar(string &s)
{
	string tmp;
	auto it_s = s.begin();
	int n = 0;
	int i = 0;
	while (it_s != s.end())
	{
		if (*it_s >= '0'&&*it_s <= '9')
		{
			auto it = it_s;
			while (it_s != s.end()&&*it_s >= '0'&&*it_s <= '9')
				it_s++;
			string t(it, it_s);
			if (t.size() > tmp.size())
				tmp = t;
			continue;
		}
		it_s++;
	}
	return tmp;
}

int main()
{
	string s;
	getline(cin, s);
	cout << LongNumChar(s) << endl;

	return 0;
}