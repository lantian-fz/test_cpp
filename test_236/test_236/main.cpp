#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-������ֻ����һ�ε�����
//һ�����������������������֮�⣬���������ֶ����������Ρ�

#include <iostream>
#include <vector>
using namespace std;

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
	if (data.empty() || data.size() < 2)
		return;
	int res = 0;
	
	for (auto e : data)
		res ^= e;
	
	//��res���������һ��1��λ��
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((res >> i) & 1) == 1)
			break;
	}

	for (auto e : data)
	{
		if (((e >> i) & 1) == 1)
			*num1 ^= e;
		else
			*num2 ^= e;
	}
}
void main()
{
	vector<int> arr{ 2, 4, 3, 6, 3, 2, 5, 5 };
	int n = 0, m = 0;
	FindNumsAppearOnce(arr, &n, &m);
	cout << n << " " << m << endl;
}