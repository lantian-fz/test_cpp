#define _CRT_SECURE_NO_WARNINGS 1
//�����������ֵ
//����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ
//��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ�����ػ��������е����ֵ��
//
//���� : nums = [1, 3, -1, -3, 5, 3, 6, 7], �� k = 3
//��� : [3, 3, 5, 5, 6, 7]
// ���� :
//	�������ڵ�λ��                ���ֵ
//	-------------- - ---- -
//	[1 3  -1] -3  5  3  6  7       3
//	1 [3  -1  -3] 5  3  6  7       3
//	1  3 [-1  -3  5] 3  6  7       5
//	1  3  -1 [-3  5  3] 6  7       5
//	1  3  -1  -3 [5  3  6] 7       6
//	1  3  -1  -3  5 [3  6  7]      7

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	if (nums.empty() || nums.size() < 2)
		return nums;
	vector<int> ret;
	deque<int> dq;
	for (int i = 0; i < nums.size(); i++)
	{
		while (dq.size() && nums[dq.back()] <= nums[i])
			dq.pop_back();

		dq.push_back(i);

		if (dq.front() < i - k + 1)
			dq.pop_front();

		if (i + 1 >= k)
			ret.push_back(nums[dq.front()]);
	}
	return ret;
}

void main()
{
	vector<int> arr = {7,2,4};
	vector<int> ret = maxSlidingWindow(arr,2);
	for (auto& e : ret)
		cout << e << " ";
	cout << endl;
}