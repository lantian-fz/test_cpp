#define _CRT_SECURE_NO_WARNINGS 1
//��������
//����һ���������ַ�'(', ')', '{', '}', '['��']', ���ַ������жϸ������ַ����Ƿ��ǺϷ�����������
//���ű�������ȷ��˳��رգ�"()"��"()[]{}"���ǺϷ����������У���"(]"��"([)]"���Ϸ���
//���룺"["      �����false
//���룺"[]"     �����true

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) 
{
	if (s.empty())
		return true;
	if (s.size() % 2 == 1)
		return false;
	if (s[0] == ')' || s[0] == '}' || s[0] == ']')
		return false;
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
		else
		{
			char tmp = st.top();
			if ((tmp == '('&&s[i] == ')') || (tmp == '{'&&s[i] == '}') || (tmp == '[' && s[i] == ']'))
				st.pop();
			else
				return false;
		}
	}
	if (st.empty())
		return true;
	else
		return false;
}

void main()
{
	string s;
	while (cin >> s)
		cout << isValid(s) << endl;
}