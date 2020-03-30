#define _CRT_SECURE_NO_WARNINGS 1
//变态跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法。

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