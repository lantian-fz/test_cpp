#define _CRT_SECURE_NO_WARNINGS 1
//�Ϸ����������ж�
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
//һ���Ϸ������Ŵ�����Ϊ��1.ֻ���������ַ���2.�����ź�������һһ��Ӧ
//����������"(()())", 6       ���أ�true
//����������"()a()()", 7      ���أ�false
//����������"()(()()", 7      ���أ�false
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
	int count = 0;//������������������������ȵ�
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