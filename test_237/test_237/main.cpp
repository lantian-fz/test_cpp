#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��ΪS����������
//����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S��
//����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
//��Ӧÿ�����԰����������������С���������

#include <iostream>
#include <vector>
using namespace std;

//˫ָ��
vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	if (array.empty())
		return array;
	int left = 0;
	int right = array.size() - 1;
	vector<int> ret;
	while (left < right)
	{
		int n = array[left] + array[right];
		if (n>sum)
			right--;
		else if (n < sum)
			left++;
		else
		{
			ret.push_back(array[left]);
			ret.push_back(array[right]);
			return ret;
		}
	}
	return ret;
}

void main()
{
	vector<int> arr = { 1, 2, 4, 7, 11, 15 };
	vector<int> arr2 = FindNumbersWithSum(arr, 15);
	for (auto e : arr2)
		cout << e << " ";
	cout << endl;
}