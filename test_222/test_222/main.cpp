#define _CRT_SECURE_NO_WARNINGS 1
//����-��ת�ַ����еĵ��� III
//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//
//���� : "Let's take LeetCode contest"
//��� : "s'teL ekat edoCteeL tsetnoc"
//ע�⣺���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
	if (s.empty() || s.size() == 1)
		return s;
	int pos = 0;
	int index = 0;
	string ret;
	while (index != s.npos)
	{
		index = s.find(' ', pos);
		if (index == s.npos)
			break;
		string tmp(s.begin() + pos, s.begin() + index);
		reverse(tmp.begin(), tmp.end());
		ret += tmp + ' ';
		pos = index + 1;
	}
	string tmp(s.begin() + pos, s.end());
	reverse(tmp.begin(), tmp.end());
	ret += tmp;
	return ret;
}

//ԭ�ط�ת
string reverseWords_2(string s)
{
	if (s.empty() || s.size() == 1)
		return s;
	int len = s.size();
	int left = 0, right = 0;
	while (right < len)
	{
		while (right < len&&s[right] != ' ')
			right++;
		int n = right-- + 1;//right�˻ؿո�ǰ
		while (left < right)
			swap(s[left++], s[right--]);
		left = n;
		right = n;
	}
	return s;
}

void main()
{
	string s = "Let's take LeetCode contest";
	cout << reverseWords_2(s) << endl;
}