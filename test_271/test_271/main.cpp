#define _CRT_SECURE_NO_WARNINGS 1
//滑动窗口最大值
//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
//你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。
//
//输入 : nums = [1, 3, -1, -3, 5, 3, 6, 7], 和 k = 3
//输出 : [3, 3, 5, 5, 6, 7]
// 解释 :
//	滑动窗口的位置                最大值
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