#define _CRT_SECURE_NO_WARNINGS 1
//����
//�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�
//������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�
//Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
//������ɫ����n(1��n��13), ͬʱ������������Ϊn������left, right, �ֱ����ÿ����ɫ���������׵�������
//���ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������
//����������4, [0, 7, 1, 6], [1, 5, 0, 6]
//���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)
#include <iostream>
#include <vector>
using namespace std;

//1. �Ȱ�����Ϊ0��ƥ��϶����ɹ��ģ�����������ȫ���ó���
//2. �ҳ�������������С�ͣ�������0���׵ģ����飬�Ѹ�������������������ȫ���ˣ�ʣ����С�ģ���һ��
//3. �ٴӶ�������У��ó����һ�����Ϳ���ƥ��
//int findMinimum(int n, vector<int> left, vector<int> right) 
//{
//	// write code here
//	int min = 0, lmin = 0, rmin = 0;
//	int lm = 26, rm = 26;
//	for (int i = 0; i < n; i++)
//	{
//		if (left[i] == 0 || right[i] == 0)
//		{
//			min += left[i];
//			min += right[i];
//		}
//		else
//		{
//			lmin += left[i];
//			rmin += right[i];
//			if (left[i] < lm)
//				lm = left[i];
//			if (right[i] < rm)
//				rm = right[i];
//		}
//	}
//	min += lmin > rmin ? (rmin - rm) : (lmin - lm);
//	return min + 2;
//}
int findMinimum(int n, vector<int> left, vector<int> right) 
{
	
}

int main()
{
	

	return 0;
}