#define _CRT_SECURE_NO_WARNINGS 1
//��������
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
//��������:����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���
//������� :���������������к�����ֵ��
//����: 3 -1 2 1
//���: 3
#include <iostream>
#include <vector>
using namespace std;

int Max_Arr(vector<int> arr)
{
	int max = arr[0];
	int num = arr[0];
	if (arr.size() == 1)
		return arr[0];
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (num < 0)
			num = arr[i];
		else
			num += arr[i];
		if (num>max)
			max = num;
	}

	return max;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp; 
		arr.push_back(tmp);
	}
	cout << Max_Arr(arr) << endl;
	return 0;
}