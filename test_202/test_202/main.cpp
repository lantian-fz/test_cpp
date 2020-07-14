#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-��ת�������С����-��ָoffer-8
//���ӣ�https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
//��Դ��ţ����
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3, 4, 5, 1, 2 }Ϊ{ 1, 2, 3, 4, 5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

#include <iostream>
#include <vector>
using namespace std;

//���ַ�����û�н�����ظ����ֵ�����
int minNumberInRotateArray_1(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
		return 0;
	int start = 0;
	int end = rotateArray.size() - 1;
	int mid = 0;
	while (rotateArray[start]>=rotateArray[end])
	{
		if (start + 1 == end)
		{
			mid = end;
			break;
		}
		mid = start + (end - start) / 2;
		if (rotateArray[mid] > rotateArray[start])
			start = mid;
		else if (rotateArray[mid] < rotateArray[end])
			end = mid;
	}
	return rotateArray[mid];
}

int minInOrder(vector<int>& arr, int index1, int index2)
{
	int n = arr[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (n > arr[i])
			n = arr[i];
	}
	return n;
}

int minNumberInRotateArray_2(vector<int> &rotateArray)
{
	if (rotateArray.size() == 0)
		return 0;
	int index1 = 0;
	int index2 = rotateArray.size() - 1;
	int mid = index1;
	while (rotateArray[index1] >= rotateArray[index2])
	{
		if (index2 - index1 == 1)
		{
			mid = index2;
			break;
		}
		mid = (index1 + index2) / 2;

		//�����������ȣ����ڸ÷�Χ��˳�����
		if (rotateArray[index1] == rotateArray[index2] && rotateArray[mid] == rotateArray[index1])
			return minInOrder(rotateArray, index1, index2);
		if (rotateArray[mid] >= rotateArray[index1])
			index1 = mid;
		else if (rotateArray[mid] <= rotateArray[index2])
			index2 = mid;
	}
	return rotateArray[mid];
}

void main()
{
	//����{0,1,1,1,1}��������ת{1,1,1,0,1}��{1,0,1,1,1}
	vector<int> arr = { 3, 4, 5, 2, 2 };
	cout << minNumberInRotateArray_2(arr) << endl;
}