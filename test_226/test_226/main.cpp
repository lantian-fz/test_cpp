#define _CRT_SECURE_NO_WARNINGS 1
//牛客-分苹果
//n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，
//每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 - 1。
//
//输入描述 :每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），
//	      接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
//输出描述 :输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 - 1。
//输入
//4
//7 15 9 5
//输出
//3


//思路：链接：https://www.nowcoder.com/questionTerminal/a174820de48147d489f64103af152709
//来源：牛客网
//如果苹果总数不能整除人数，证明无论怎么分，总会有人多出一些
//苹果。 如果能整除，那么每个人的最终的苹果数目一定是平均数，不然不可能相等。所以
//只需要把低于平均数那一部分补上，把高于平均数那一部分减掉就可以了。当然如果， 补
//上的那一部分不能整除2，证明这个人是不能通过2个苹果的转移来达到平均数，即无论怎么
//分，也不可能每个人的苹果都一样。
#include<iostream>
#include<vector>
using namespace std;

int fun(vector<int> arr,int sum)
{
	if (sum%arr.size() != 0)
		return -1;
	int n = sum / arr.size();
	int ret = 0;
	for (auto e : arr)
	{
		if (e > n)
		{
			if ((e - n) % 2 == 0)
				ret += (e - n) / 2;
			else
				return -1;
		}
		else if (e < n)
		{
			if ((n - e) % 2 == 0)
				ret += (n - e) / 2;
			else
				return -1;
		}
	}
	return ret/2;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int sum = 0;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		cout << fun(arr,sum) << endl;
	}

	return 0;
}