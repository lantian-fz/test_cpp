#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-翻转单词顺序
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
//标点符号和普通字母一样处理。例如输入字符串“I am a student.”输出“student.a am I”

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ReverseSentence(string str)
{
	if (str.empty() || str.size() == 1)
		return str;
	reverse(str.begin(), str.end());
	string::iterator it = str.begin();
	while (it != str.end())
	{
		string::iterator left = it;
		while (it != str.end() && (*it != ' '))
			it++;
		reverse(left, it);
		if (it == str.end())
			break;
		it++;
	}
	return str;
}

void main()
{
	string s;
	while (getline(cin, s))
		cout << ReverseSentence(s) << endl;
}