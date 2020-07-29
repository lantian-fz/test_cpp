#define _CRT_SECURE_NO_WARNINGS 1
//����-��֤���Ĵ�
//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//
//����: "A man, a plan, a canal: Panama"           ���: true
//
//����: "race a car"                               ���: false

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) 
{
	if (s.empty())
		return true;
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		//��ȫ��ת��Ϊ��д
		if (s[i] >= 'a'&&s[i] <= 'z')
			s[i] -= 32;
		if (s[j] >= 'a'&&s[j] <= 'z')
			s[j] -= 32;
		if ((s[i]<'A' || s[i]>'Z') && (s[i]<'0' || s[i]>'9'))
		{
			i++;
			continue;
		}
		if ((s[j]<'A' || s[j]>'Z') && (s[j]<'0' || s[j]>'9'))
		{
			j--;
			continue;
		}
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool isPalindrome_2(string s)
{
	if (s.empty())
		return true;
	string str;
	for (auto i : s)
	{
		if (i >= 'a'&&i <= 'z')
			i -= 32;
		if (i >= 'A'&&i <= 'Z' || i >= '0'&&i <= '9')
			str.push_back(i);
	}
	string str2(str);
	reverse(str2.begin(), str2.end());
	if (strcmp(str.c_str(), str2.c_str()) == 0)
		return true;
	return false;
}

void main()
{
	string s = "ab2a";
	cout << isPalindrome_2(s) << endl;
}