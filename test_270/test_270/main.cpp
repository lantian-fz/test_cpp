#define _CRT_SECURE_NO_WARNINGS 1
//ÿ���¶�
//�����ÿ�� ���� �б���������һ���б���Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ���������
//�����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
//���磬����һ���б� temperatures = [73, 74, 75, 71, 69, 72, 76, 73]��������Ӧ����[1, 1, 4, 2, 1, 1, 0, 0]��
//��ʾ������ �б��ȵķ�Χ��[1, 30000]��ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ�������[30, 100] ��Χ�ڵ�������

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) 
{
	if (T.empty())
		return T;
	vector<int> ret(T.size(),0);
	stack<int> st;//���¶��±�
	for (int i = 0; i<T.size(); i++)
	{
		while (st.size() && T[i]>T[st.top()])
		{
			int tmp = st.top();
			ret[tmp] = i - tmp;
			st.pop();
		}
		st.push(i);
	}
	return ret;
}

void main()
{
	vector<int> arr = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> ret = dailyTemperatures(arr);
	for (auto& e : ret)
		cout << e << " ";
	cout << endl;
}