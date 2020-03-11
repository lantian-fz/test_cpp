#define _CRT_SECURE_NO_WARNINGS 1
//201301 JAVA 题目2 - 3级
//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
//沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
//输入描述 :输入两个正整数
//输出描述 :返回结果
//输入: 2
//      2
//输出: 6
#include <iostream>
#include <vector>
using namespace std;

//从(m, n)—>(0, 0)就分两步走：
//往右走一步：f(m, n - 1)—>(0, 0) 加上下走一步：f(m - 1, n)—>(0, 0)
//注意：但凡是触碰到边界，也就是说f(x, 0)或者f(0, x)都只有一条直路可走了，这里的x是变量哈。
//f(m, n) = f(m, n - 1) + f(m - 1, n)
int LeftRight(int n, int m)//递归
{
	if (n == 0 || m == 0)
		return 1;
	else
		return LeftRight(n - 1, m) + LeftRight(n, m - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << LeftRight(n, m) << endl;

	return 0;
}

//int main()//数学方法
//{
//	//共有  A(m+n,m+1)/n!  种走法
//	int n, m;
//	while (cin >> n >> m)
//	{
//		int get = 1;
//		for (int i = n + m; i>n; i--)
//			get *= i;
//		for (int i = 2; i <= m; i++)
//			get /= i;
//		cout << get << endl;
//	}
//	return 0;
//}

//int main()//动态规划
//{
//	int m, n;
//	while (cin >> m >> n) {
//		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
//		for (int i = 0; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				if (i == 0 && j == 0) {
//					dp[i][j] = 1;
//					continue;
//				}
//				if (i == 0) {    // 上边界
//					dp[i][j] = dp[i][j - 1];
//				}
//				else if (j == 0) {    // 左边界
//					dp[i][j] = dp[i - 1][j];
//				}
//				else {
//					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//				}
//			}
//		}
//		cout << dp[n][m] << endl;
//	}
//
//	return 0;
//}