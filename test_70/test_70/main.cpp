#define _CRT_SECURE_NO_WARNINGS 1
//最近公共祖先
//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。
//请设计一个算法，求出a和b点的最近公共祖先的编号。
//给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
//测试样例：2，3
//返回：1
#include <iostream>
#include <math.h>
using namespace std;

int getLCA_1(int a, int b) 
{
	while (a != b)
	{
		if (a > b)
			a /= 2;
		else if (a < b)
			b /= 2;
	}
	return a;
}

int getLCA_2(int a, int b)
{
	if (a>b)
		return getLCA_2(a / 2, b);
	else if (a < b)
		return getLCA_2(a, b / 2);
	else
		return a;
}

int main()
{
	int a = 0;
	int b = 0;
	cin>>a>>b;
	cout << getLCA_1(a, b) << endl;
	cout << getLCA_2(a, b) << endl;

	return 0;
}