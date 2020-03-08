#define _CRT_SECURE_NO_WARNINGS 1
//合法括号序列判断
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
//一个合法的括号串定义为：1.只包括括号字符；2.左括号和右括号一一对应
//测试样例："(()())", 6       返回：true
//测试样例："()a()()", 7      返回：false
//测试样例："()(()()", 7      返回：false
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool chkParenthesis_1(string A, int n)
{
	if (n % 2 == 1 || A[0] == ')')
		return false;
	stack<char> st;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] != '(' && A[i] != ')')
			return false;
		if (A[i] == '(')
		{
			st.push(A[i]);
			count = 0;
		}
		if (st.size() != 0)
		{
			if (A[i] == ')' && st.top() == '(')
			{
				st.pop();
			}
		}
		else
			count++;
		if (count > 1)
			return false;
	}
	if (st.size() != 0)
		return false;
	return true;
}

bool chkParenthesis_2(string A, int n)
{
	if (n % 2 == 1 || A[0] == ')')
		return false;
	int count = 0;//计数器，左右括号数量是相等的
	for (int i = 0; i < n; i++)
	{
		if (A[i] == '(')
			count++;
		if (A[i] == ')')
			count--;
		if (count < 0)
			return false;
	}
	if (count == 0)
		return true;
	return false;
}

int main()
{
	string a;
	int n = 0;
	cin >> a >> n;

	cout << chkParenthesis_1(a, n) << endl;
	cout << chkParenthesis_2(a, n) << endl;

	return 0;
}