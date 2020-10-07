#define _CRT_SECURE_NO_WARNINGS 1
//�ϲ��������������
//��������������������� A��B ���뽫����B �ϲ�������A �У����һ�����������
//ע�⣺���Լ���A �������㹻�Ŀռ��� B�����Ԫ�أ� A�� B�г�ʼ��Ԫ����Ŀ�ֱ�Ϊm ��n

#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n)
{
	int index = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	while (i>=0 && j>=0)
		A[index--] = A[i]>B[j] ? A[i--] : B[j--];
	while (j >= 0)
		A[index--] = B[j--];
}

void main()
{
	int arr1[10] = { 1, 3, 5, 6, 9 };
	int arr2[] = { 2, 4, 5, 8, 10 };
	merge(arr1, 5, arr2, 5);
	for (auto e : arr1)
		cout << e << " ";
	cout << endl;
}