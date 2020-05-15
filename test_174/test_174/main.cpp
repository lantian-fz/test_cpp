#define _CRT_SECURE_NO_WARNINGS 1
//����-560.��ΪK��������
//����һ�����������һ������ k������Ҫ�ҵ��������к�Ϊ k ��������������ĸ�����
//
//����:nums = [1,1,1], k = 2
//���: 2 , [1,1] �� [1,1] Ϊ���ֲ�ͬ�������
//˵�� :����ĳ���Ϊ [1, 20,000]��
//������Ԫ�صķ�Χ�� [-1000, 1000] �������� k �ķ�Χ�� [-1e7, 1e7]��

#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) //��ǿͨ��
{
	if (nums.size() == 1)
		return nums[0] == k ? 1 : 0;
	int count = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		int n = 0;
		for (int j = i; j >=0; j--)
		{
			n += nums[j];
			if (n == k)
			{
				count++;
				//break;
			}
		}
	}
	return count;
}

int main()
{
	vector<int> arr = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int k = 0;
	cout << subarraySum(arr, k) << endl;

	return 0;
}