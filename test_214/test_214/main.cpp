#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�����������ĺ����������
//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
//����������Yes, �������No���������������������������ֶ�������ͬ��

#include <iostream>
#include <vector>
using namespace std;

bool Verify(vector<int> arr, int len)
{
	if (arr.size() == 0 || len == 0)
		return false;
	int root = arr[len - 1];
	vector<int>::iterator it = arr.begin();

	int i = 0;
	for (; i < len - 1; i++,it++)
	{
		if (arr[i]>root)
			break;
	}

	int j = i;
	for (; j < len - 1; j++)
	{
		if (arr[j] < root)
			return false;
	}

	bool left = true;
	if (i>0)
		left = Verify(arr, i);
	bool right = true;
	vector<int> tmp(it, arr.end());
	if (i < len - 1)
		right = Verify(tmp, len - i - 1);
	return (left&&right);
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.size() == 0)
		return false;
	return Verify(sequence, sequence.size());
}

void main()
{
	vector<int> arr = { 5, 7, 6, 9, 11, 10, 8 };
	cout << VerifySquenceOfBST(arr) << endl;
}