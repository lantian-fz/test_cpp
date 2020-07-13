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

int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
		return 0;
	int start = 0;
	int end = rotateArray.size() - 1;
	while ((start + 1) != end)
	{
		int mid = (start + end) / 2;
		if (rotateArray[mid] > rotateArray[start])
			start = mid;
		else if (rotateArray[mid] < rotateArray[end])
			end = mid;
	}
	return rotateArray[end];
}

void main()
{
	vector<int> arr = { 3, 4, 5, 1, 2 };
	cout << minNumberInRotateArray(arr) << endl;
}