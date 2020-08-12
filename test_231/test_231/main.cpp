#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-����
//��ֻ����������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ������������7�� 
//ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool GetUglyNumber(int n)
{
	while (n % 2 == 0)
		n /= 2;
	while (n % 3 == 0)
		n /= 3;
	while (n % 5 == 0)
		n /= 5;
	return (n == 1) ? true : false;
}

//ţ��δͨ������ʱ
int GetUglyNumber_Solution(int index) 
{
	if (index <= 0)
		return 0;
	int ret = 0;
	int num = 0;
	while (num < index)
	{
		ret++;
		if (GetUglyNumber(ret))
			num++;
	}
	return ret;
}

//�ռ任ʱ��,Ҫ��n����������Ҫ����n���ռ�
int GetUglyNumber_Solution_2(int index)
{
	if (index < 7)
		return index;
	vector<int> arr(index);
	arr[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0;
	
	for (int i = 1; i < index; i++)
	{
		arr[i] = min(arr[t2] * 2, min(arr[t3]*3, arr[t5]*5));
		if (arr[i] == arr[t2] * 2)
			t2++;
		if (arr[i] == arr[t3] * 3)
			t3++;
		if (arr[i] == arr[t5] * 5)
			t5++;
	}
	return arr[index - 1];
}

void main()
{
	int n = 0;
	while (cin >> n)
		cout << GetUglyNumber_Solution_2(n) << endl;
}