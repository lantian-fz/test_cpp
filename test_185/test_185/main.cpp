#define _CRT_SECURE_NO_WARNINGS 1
//力扣-62.不同路径
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//问总共有多少条不同的路径？
//示例 1:
//输入: m = 3, n = 2
//输出: 3
//解释:
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向右 -> 向下
//2. 向右 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向右
//
//示例 2:
//输入: m = 7, n = 3
//输出: 28

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) 
{
	if (m <= 0 || n <= 0)
		return 0;
	vector<vector<int>> dp(m, vector<int>(n,0));

	//只有一列或只有靠一行时只有一条路径
	for (int i = 0; i < m; i++)
		dp[i][0] = 1;
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	return dp[m - 1][n - 1];
}

int main()
{
	int m = 0, n = 0;
	while (cin >> m >> n)
		cout << uniquePaths(m, n) << endl;


	return 0;
}


//#include <iostream>
//#include <string>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//struct A{
//	long a1;
//	short a2;
//	int a3;
//	double *a4;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	return 0;
//}

//int Palindrome(string &a, string &b)
//{
//	int ret = 0;
//	for (size_t i = 0; i <= a.size(); i++)
//	{
//		string tmp = a;
//		tmp.insert(i, b);
//		string re = tmp;
//		reverse(re.begin(), re.end());
//		if (strcmp(tmp.c_str(), re.c_str()) == 0)
//			ret++;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	string a;
//	string b;
//	//cin >> a >> b;
//	getline(cin, a);
//	getline(cin, b);
//
//	cout << Palindrome(a, b) << endl;
//
//	return 0;
//}

//class B0//基类BO声明
//{
//public://外部接口
//	virtual void display()//虚成员函数
//	{
//		cout << "B0::display0" << endl;
//	}
//};
//class B1 :public B0//公有派生
//{
//public:
//	void display() { cout << "B1::display0" << endl; }
//};
//class D1 : public B1//公有派生
//{
//public:
//	void display(){ cout << "D1::display0" << endl; }
//};
//void fun(B0 ptr)//普通函数
//{
//	ptr.display();
//}
//int main()//主函数
//{
//	B0 b0;//声明基类对象和指针
//	B1 b1;//声明派生类对象
//	D1 d1;//声明派生类对象
//	fun(b0);//调用基类B0函数成员
//	fun(b1);//调用派生类B1函数成员
//	fun(d1);//调用派生类D1函数成员
//
//	return 0;
//}

//int main()
//{
//	int a; float b, c;
//	scanf("%3d%3f%4f", &a, &b, &c);
//	printf("\na=%d,b=%d,c=%f\n", a, b, c);
//
//	return 0;
//}
