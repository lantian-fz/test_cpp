#define _CRT_SECURE_NO_WARNINGS 1
//��̬��̨��
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
//�����������һ��n����̨���ܹ��ж�����������

#include <iostream>
using namespace std;
//1 2 4 8 16 32 64
int jumpFloorII(int number) 
{
	if (number == 1)
		return 1;
	int ret = 1;
	for (int i = 2; i <= number; i++)
		ret = 2 * ret;
	return ret;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << jumpFloorII(n) << endl;

	return 0;
}