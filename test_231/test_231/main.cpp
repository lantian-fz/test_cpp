#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-丑数
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

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