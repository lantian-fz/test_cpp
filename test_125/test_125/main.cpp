#define _CRT_SECURE_NO_WARNINGS 1
//���� 414. ���������
//����һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
//����: [3, 2, 1]
//���: 1
//����: ����������� 1.
//
//����: [1, 2]
//���: 2
//����: ���������������, ���Է��������� 2 .
//
//����: [2, 2, 3, 1]
//���: 1
//����: ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�������������ֵΪ2���������Ƕ��ŵڶ���

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int thirdMax(vector<int> &nums)
{
	set<int> st(nums.begin(),nums.end());
	auto it = st.end();
	if (st.size() < 3)
		return *(--it);
	else
		return *(------it);
}

int main()
{
	vector<int> nums = { 2, 1};

	cout << thirdMax(nums) << endl;

	return 0;
}