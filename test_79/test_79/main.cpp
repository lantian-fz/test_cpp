#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-��������1�ĸ���-��ָoffer-10
//��ʵ�����½ӿ�
//public   static   int  findNumberOf1(int num)
//{
//	return  0;
//} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
//�������� :����һ������
//������� :����������������1�ĸ���
//����: 5
//���: 2
#include <iostream>
using namespace std;
//����Ҫ�жϵ���
int findNumberOf1(int num)
{
	int ret = 0;
	if (num < 0)
	{
		num = -num;
		ret++;
	}
	for (int i = 0; i<32; i++)
	{
		if (((num >> i) & 1) == 1)
			ret++;
	}
	return ret; 
}

//����1�������ж�����
int findNumberOfl_2(int num)
{
	size_t i = 1;
	int ret = 0;
	while (i)
	{
		if (num&i)
			++ret;
		i <<= 1;
	}
	return ret;
}

//������������1��λ�����㣬�൱�ڰ������ұߵ�1���0����ô��������Ķ��������ж��ٸ�1���Ϳ��Խ��ж��ٴ�����������
int findNumberOfl_3(int num)
{
	int ret = 0;
	while (num)
	{
		++ret;
		num = (num - 1)&num;
	}
	return ret;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << findNumberOfl_3(n) << endl;

	return 0;
}