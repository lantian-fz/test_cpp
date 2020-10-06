#define _CRT_SECURE_NO_WARNINGS 1
//括号序列
//给出一个仅包含字符'(', ')', '{', '}', '['和']', 的字符串，判断给出的字符串是否是合法的括号序列
//括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
//输入："["      输出：false
//输入："[]"     输出：true

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