#define _CRT_SECURE_NO_WARNINGS 1
//�����Ʋ���
//������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ, ���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
//����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i - j + 1��
//����������1024��19��2��6
//���أ�1100
#include <iostream>
using namespace std;

int binInsert(int n, int m, int j, int i) 
{
	m <<= j;
	n |= m;
	return n;
}

int main()
{
	cout << binInsert(1024, 19, 2, 6) << endl;

	return 0;
}