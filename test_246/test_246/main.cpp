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
void main()
{
	vector<int> arr{ 3, 2, 1, 5, 6, 4 };
	cout << findKthLargest(arr, 0) << endl;
}