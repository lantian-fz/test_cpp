#define _CRT_SECURE_NO_WARNINGS 1
//牛客-用两个栈实现队列-剑指offe-7
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);//入栈
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