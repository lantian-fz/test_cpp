#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-包含min函数的栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
	void push(int value) {
		sk1.push(value);
		if (sk2.empty())
			sk2.push(value);
		else if (value <= sk2.top())
			sk2.push(value);
	}
	void pop() {
		assert(sk1.size() > 0 && sk2.size() > 0);

		if (sk1.top() == sk2.top())
			sk2.pop();
		sk1.pop();
	}
	int top() {
		assert(sk1.size() > 0 && sk2.size() > 0);
		return sk1.top();
	}
	int min() {
		assert(sk1.size() > 0 && sk2.size() > 0);
		return sk2.top();
	}
public:
	stack<int> sk1;//数据栈
	stack<int> sk2;//辅助栈
};

void main()
{
	Solution s;
	cout << s.min() << endl;
}