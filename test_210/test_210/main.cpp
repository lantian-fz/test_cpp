#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-����min������ջ
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
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
	stack<int> sk1;//����ջ
	stack<int> sk2;//����ջ
};

void main()
{
	Solution s;
	cout << s.min() << endl;
}