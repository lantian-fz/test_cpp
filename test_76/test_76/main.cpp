#define _CRT_SECURE_NO_WARNINGS 1
//跳石板
//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能
//往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，
//他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
//例如：N = 4，M = 24：    4->6->8->12->18->24   于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
//输入描述:输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
//输出描述:输出小易最少需要跳跃的步数,如果不能到达输出-1
//输入： 4 24
//输出： 5

#include <iostream>
using namespace std;

int Num(int n,int count)
{
	for (int i = count - 1; i > 1; i--)
	{
		if (n%i == 0)
			return i;
	}
	return 0;
}
int ret = 0;

//int Min(int n, int m, int count)
//{
//	int x = Num(n, n);
//	if (n == m)
//		return 1;
//	else
//	{
//		if (n + x <= m)
//		{
//			Min(n + x, m, x);
//		}
//		else
//		{
//			while (n + x > m)
//			{
//				x = Num(n, x);
//			}
//		}
//	}
//}
int Min(int n, int m,int x)
{
	int tmp = 0;
	if (n == m)
		return 1;
	int count = Num(n, x);
	while (n + count < m&&count!=0)
	{
		n += count;
		count = Num(n, n);
		ret++;
	}
	tmp = Num(n,count);

	while (n + count != m&&count != 0)
	{
		count = Num(n, count);

		while (n + count < m&&count!=0)
		{
			n += count;
			count = Num(n, n);
			ret++;
		}
	}
	if (count == 0)
	{
		n -= tmp;
		x = Num(n, n);
		return Min(n, m, x) + 1;
	}
	return -1;
}
int MinNum(int n, int m)
{
	//int count = Num(n, n);//n的最大约数
	//if (n == m)
	//	return 1;
	//else
	int count = Num(n, n);//n的最大约数
	int r = Min(n, m, n);


	return -1;
}

int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		cout << MinNum(n, m) << endl;
	}

	return 0;
}