#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-��������˳��ʹ����λ��ż��ǰ��
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
//���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

#include <iostream>
#include <vector>
using namespace std;

//δͨ��ţ�ͣ��������λ�÷����˱仯
void reOrderArray_1(vector<int> &array) 
{
	int left = 0;
	int right = array.size() - 1;
	while (left < right)
	{
		//ָ�������Ƶ�ż��λ��
		while (left < right && (array[left] & 1) == 1)
			left++;
		//ָ����ǰ�Ƶ�����λ��
		while (left < right && (array[right] & 1) == 0)
			right--;
		if (left < right)
		{
			int tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
		}
	}
}

//�½�һ�����飬�ռ任ʱ��
void reOrderArray_2(vector<int> &array)
{
	vector<int> arr;
	for (auto e : array)
	{
		if ((e & 1) != 0)
			arr.push_back(e);
	}
	for (auto e : array)
	{
		if ((e & 1) == 0)
			arr.push_back(e);
	}
	array = arr;
}

void main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	reOrderArray_2(arr);
	for (auto e : arr)
		cout << e << " ";
}