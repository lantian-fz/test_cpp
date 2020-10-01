#define _CRT_SECURE_NO_WARNINGS 1
//�����еĵ�K�����Ԫ��
//��δ������������ҵ��� k ������Ԫ�ء���ע�⣬
//����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
//
//����: [3,2,1,5,6,4] �� k = 2           ���: 5
//����: [3,2,3,1,2,4,5,5,6] �� k = 4     ���: 4

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
	if (nums.empty() || k < 1)
		return -1;
	priority_queue<int> q(nums.begin(), nums.end());
	for (int i = 0; i < k - 1; i++)
		q.pop();
	return q.top();
}
//int findKthLargest_2(vector<int>& nums, int k)
//{
//	multiset<int> st(nums.begin(), nums.end());
//	int i = 0;
//	for (auto e : st)
//	{
//		i++;
//
//		if (i == k)
//			return e;
//	}
//	return 0;
//}
void main()
{
	vector<int> arr{ 1, 3, 5, 2, 2 };
	cout << findKthLargest(arr, 3) << endl;
}