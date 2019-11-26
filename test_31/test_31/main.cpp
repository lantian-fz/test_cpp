#define _CRT_SECURE_NO_WARNINGS 1
//每组数据输入一个字符串，字符串中最大长度为100，且只包含字母，
//不可能为空串，区分大小写

//输出描述：每组数据一行，按字符串原有的字符顺序，输出字符串集合，即重复出现并靠后的字母不输出
//例：输入 abcqweracb      输出  abcqwer
#include <iostream>
#include <string>
using namespace std;

string& Str(string& s)
{
	int arr[255] = { 0 };
	int sz = s.size();
	string tmp;
	tmp.resize(100);
	for (int i = 0; i<sz; i++)
	{
		arr[s[i]]++;
	}
	for (int i = 0; i<sz; i++)
	{
		if (arr[s[i]] != 0)
		{
			tmp[i] = s[i];
			if (arr[s[i]]>1)
				arr[s[i]] = 0;
		}
	}
	s = tmp;
	return s;
}

int main()
{
	string str;
	str.resize(100);
	cin >> str;
	cout << Str(str) << endl;


	return 0;
}