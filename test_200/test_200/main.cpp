#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-������ջʵ�ֶ���-��ָoffe-7
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);//��ջ
	}

	int pop()
	{
		if (stack2.size() == 0)
		{
			while (stack1.size() > 0)
			{
				int data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		int head = stack2.top();
		stack2.pop();
		return head;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

void main()
{
	Solution q;
	q.push(1);
	q.push(2);
	cout << q.pop() << endl;
}