#define _CRT_SECURE_NO_WARNINGS 1
//iNOC产品部 - 杨辉三角的变形
//          1
//       1  1  1
//     1  2  3  2  1
//  1 3 6  7  6  3  1
// 1 4 10 16 19  16 10  4  1
//1 5 15 30 45 51 45 30 15 5 1
//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，
//3个数之和（如果不存在某个数，认为该数就是0）。
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
//输入描述 : 输入一个int整数  输入n(n <= 1000000000)
//输出描述 :输出返回的int值
//输入: 4
//输出: 3
#include <iostream>
#include <vector>
using namespace std;

int Print_1(int n)
{
	if (n < 3)
		return -1;
	else if (n % 2 == 1)
		return 2;
	else if (n % 4 == 0)
		return 3;
	else
		return 4;
}

int Print_2(int n)
{
	vector<vector<int>> arr(n, vector<int>(2 * n - 1, 0));
	arr[0][n - 1] = arr[n - 1][0] = arr[n - 1][2 * n - 2] = 1;//最边缘都为1
	if (n < 3)
		return -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < 2 * n - 2; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
		}
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (arr[n - 1][i] != 0 && arr[n - 1][i] % 2 == 0)
			return i + 1;
	}
	return -1;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << Print_2(n) << endl;

	return 0;
}