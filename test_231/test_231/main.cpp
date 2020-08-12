#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-丑数
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

#include <iostream>
#include <vector>
#include <algorithm>
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

//牛客未通过，超时
int GetUglyNumber_Solution(int index) 
{
	if (index <= 0)
		return 0;
	int ret = 0;
	int num = 0;
	while (num < index)
	{
		ret++;
		if (GetUglyNumber(ret))
			num++;
	}
	return ret;
}

//空间换时间,要第n个丑数就需要开辟n个空间
int GetUglyNumber_Solution_2(int index)
{
	if (index < 7)
		return index;
	vector<int> arr(index);
	arr[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0;
	
	for (int i = 1; i < index; i++)
	{
		arr[i] = min(arr[t2] * 2, min(arr[t3]*3, arr[t5]*5));
		if (arr[i] == arr[t2] * 2)
			t2++;
		if (arr[i] == arr[t3] * 3)
			t3++;
		if (arr[i] == arr[t5] * 5)
			t5++;
	}
	return arr[index - 1];
}

void main()
{
	int n = 0;
	while (cin >> n)
		cout << GetUglyNumber_Solution_2(n) << endl;
}