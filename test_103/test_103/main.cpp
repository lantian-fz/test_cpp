#define _CRT_SECURE_NO_WARNINGS 1
//���üӼ��˳����ӷ�
//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�� + �� - ��*�� / ����������š�
#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	while (num2!=0)
	{
		int x = num1^num2;
		num2 = (num1&num2) << 1;
		num1 = x;
	}
	return num1;
}

int main()
{
	int m = 0;
	int n = 0;
	while (cin >> m >> n)
	{
		cout << Add(m, n) << endl;
	}
	return 0;
}