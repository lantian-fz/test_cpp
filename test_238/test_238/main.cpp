#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��ΪS��������������
//����һ������S����ӡ�����к�ΪS��������������(���ٺ���������)��
//���磺����15��1+2+3+4+5=4+5+6=7+8=15�����о�Ϊ1��5,4��6,7��8

#include<iostream>
#include<vector>
using namespace std;

void FindContinuousSequence(vector<vector<int>>&arr, int left, int right)
{
	vector<int> tmp;
	for (int i = left; i <= right; i++)
		tmp.push_back(i);
	arr.push_back(tmp);
}
//˫ָ��
vector<vector<int>> FindContinuousSequence(int sum)
{
	vector<vector<int>> arr;
	if (sum < 3)
		return arr;
	int left = 1;
	int right = 2;
	int mid = (sum + 1) / 2;
	int cursum = left + right;
	while (left < mid)
	{
		if (cursum == sum)
			FindContinuousSequence(arr, left, right);
		while (cursum>sum&&left < mid)
		{
			cursum -= left;
			left++;
			if (cursum == sum)
				FindContinuousSequence(arr, left, right);
		}
		right++;
		cursum += right;
	}
	return arr;
}

void main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<vector<int>> arr = FindContinuousSequence(n);
		for (auto e : arr)
		{
			for (auto i : e)
				cout << i << " ";
			cout << endl;
		}
	}
}