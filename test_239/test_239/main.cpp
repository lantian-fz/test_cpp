#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��ת����˳��
//����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
//�����ź���ͨ��ĸһ���������������ַ�����I am a student.�������student.a am I��

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