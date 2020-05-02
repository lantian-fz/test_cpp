#define _CRT_SECURE_NO_WARNINGS 1
//����-4.Ѱ�����������������λ��
//����������СΪ m �� n ���������� nums1 �� nums2��
//�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��
//����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�
//ʾ�� 1:
//nums1 = [1, 3]
//nums2 = [2]
//����λ���� 2.0
//
//ʾ�� 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//����λ����(2 + 3) / 2 = 2.5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> num = nums1;
	for (size_t i = 0; i < nums2.size(); i++)
		num.push_back(nums2[i]);
	sort(num.begin(), num.end());
	if (num.size() % 2 == 0)
	{
		int x = num.size() / 2;
		double mid = (num[x] + num[x - 1]) / 2.0;
		return mid;
	}
	else
	{
		double mid = num[num.size() / 2];
		return mid;
	}
}

int main()
{
	vector<int> nums1 = { 1, 2 };
	vector<int> nums2 = { 3, 4 };
	cout << findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}