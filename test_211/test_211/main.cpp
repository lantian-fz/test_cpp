#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-ջ��ѹ�롢��������
//���ӣ�https ://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106
//��Դ��ţ����
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ����
//��Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//��ָoffer�ⷨ
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

		//���в��Ϸ�
		if (sk.top() != popV[j])
			break;
		sk.pop();
		j++;
	}
	if (sk.empty() && j == pushV.size())
		return true;
	return false;
}

//ţ�ʹ���ⷨ
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