#define _CRT_SECURE_NO_WARNINGS 1
//����ӷ�
//���дһ��������������������ӡ�����ʹ�� + �����������������
//��������int A��B���뷵��A��B��ֵ
//����������1, 2     ���أ�3
#include <iostream>
using namespace std;

int addAB(int A, int B) 
{
	if (B == 0)
		return A;
	return addAB(A^B, (A&B) << 1);
}

int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;

	cout << addAB(a, b) << endl;

	return 0;
}