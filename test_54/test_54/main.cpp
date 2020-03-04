#define _CRT_SECURE_NO_WARNINGS 1
//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述 :个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述 :在一行内输出str中里连续最长的数字串。
//输入:abcd12345ed125ss123456789
//输出:123456789
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