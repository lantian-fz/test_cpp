#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-����
//��ֻ����������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ������������7�� 
//ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

#include <iostream>
using namespace std;

bool GetUglyNumber(int n)
{
	while (n % 2 == 0)
		n /= 2;
	while (n % 3 == 0)
		n /= 3;
	while (n % 5 == 0)
		n /= 5;
	return (n == 1) ? true : false;
}

int GetUglyNumber_Solution(int index) 
{

}

void main()
{
	int n = 0;
	while (cin >> n)
		cout << GetUglyNumber_Solution(n) << endl;
}