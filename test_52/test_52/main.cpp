#define _CRT_SECURE_NO_WARNINGS 1
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, 
//��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪���� ���� ���԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
//�������� :����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
//          �ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡�
//������� :���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
//����
//6
//1 2 3 2 2 1
//��� 2
#include <iostream>
#include <vector>
using namespace std;
//˼·:�ж�ÿ�������еĵڶ������ȵ�һ��������С��ȷ���Ƿ�����
size_t Estimate(vector<long> arr)
{
	size_t num = 1;//������������������һ��
	int count = 0;//�ж��Ƿ�����
	for (size_t i = 1; i < arr.size(); i++)
	{

		if (arr[i] > arr[i - 1])
		{
			if (count == 0)
				count = 1;
			if (count == -1)
			{
				count = 0;
				num++;
			}
		}
		else if (arr[i] < arr[i - 1])
		{
			if (count == 0)
				count = -1;
			if (count == 1)
			{
				count = 0;
				num++;
			}
		}
	}

	return num;
}

int main()
{
	size_t n = 0;
	cin >> n;
	vector<long> arr;
	for (size_t i = 0; i < n; i++)
	{
		long count = 0;
		cin >> count;
		arr.push_back(count);
	}

	cout << Estimate(arr) << endl;

	return 0;
}