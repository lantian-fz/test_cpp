#define _CRT_SECURE_NO_WARNINGS 1
//����-1-����֮��
//����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�
//
//���� nums = [2, 7, 11, 15], target = 9
//��Ϊ nums[0] + nums[1] = 2 + 7 = 9   ���Է���[0, 1]

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> arr(2, 0);
	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] == target - nums[j])
			{
				arr[0] = i;
				arr[1] = j;
				return arr;
			}
		}
	}
	return arr;
}

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> &arr = twoSum(nums, target);
	cout << arr[0] << ", " << arr[1] << endl;

	return 0;
}