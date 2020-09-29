#define _CRT_SECURE_NO_WARNINGS 1
//����-�����ظ�Ԫ��
//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
//
//����: [1,2,3,1]                      ���: true
//
//����: [1,2,3,4]                      ���: false
//
//����: [1,1,1,3,3,4,3,2,4,2]          ���: true

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	if (nums.empty() || nums.size() == 1)
		return false;
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
		mp[nums[i]]++;
	for (auto e : mp)
	{
		if (e.second >= 2)
			return true;
	}
	return false;
}

void main()
{
	vector<int> arr = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	cout << containsDuplicate(arr) << endl;
}