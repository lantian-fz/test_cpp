#define _CRT_SECURE_NO_WARNINGS 1
//��������Ľ��� I
//�����������飬��дһ���������������ǵĽ�����
//
//���룺nums1 = [1, 2, 2, 1], nums2 = [2, 2]           �����[2]
//���룺nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]     �����[9, 4]
//
//˵�����������е�ÿ��Ԫ��һ����Ψһ�ġ����ǿ��Բ�������������˳��

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> ret;
	if (nums1.empty() || nums2.empty())
		return ret;
	unordered_set<int> st1(nums1.begin(),nums1.end());
	unordered_set<int> st2(nums2.begin(), nums2.end());
	for (auto e : st1)
	{
		if (st2.find(e) != st2.end())
			ret.push_back(e);
	}
	
	return ret;
}

void main()
{
	vector<int> arr1 = { 1, 2, 3, 1 };
	vector<int> arr2 = { 2, 2 };
	vector<int> ret = intersection(arr1, arr2);
	for (auto e : ret)
		cout << e << " ";
	cout << endl;
}