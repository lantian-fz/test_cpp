#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-栈的压入、弹出序列
//链接：https ://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106
//来源：牛客网
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列
//对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//剑指offer解法
bool IsPopOrder_1(vector<int> pushV, vector<int> popV) 
{
	if (pushV.size() == 0 || popV.size()==0||pushV.size()!=popV.size())
		return false;
	
	stack<int> sk;
	int i = 0, j = 0;
	while (j < pushV.size())
	{
		while (sk.empty() || sk.top() != popV[j])
		{
			if (i == pushV.size())
				break;
			sk.push(pushV[i++]);
		}

		//序列不合法
		if (sk.top() != popV[j])
			break;
		sk.pop();
		j++;
	}
	if (sk.empty() && j == pushV.size())
		return true;
	return false;
}

//牛客大神解法
bool IsPopOrder_2(vector<int> pushV, vector<int> popV)
{
	if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
		return false;
	stack<int> sk;
	for (int i = 0, j = 0; i < pushV.size();)
	{
		sk.push(pushV[i++]);
		while (j < popV.size() && sk.top() == popV[j])
		{
			sk.pop();
			j++;
		}
	}
	return sk.empty();
}

void main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder_2(pushV, popV) << endl;
}