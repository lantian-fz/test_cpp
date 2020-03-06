#define _CRT_SECURE_NO_WARNINGS 1
//不要二
//二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，
//任意两块蛋糕的欧几里得距离不能等于2。对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
//( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根,小易想知道最多可以放多少块蛋糕在网格盒子里。
//输入描述:每组数组包含网格长宽W,H，用空格分割.(1 ≤ W、H ≤ 1000)
//输出描述:输出一个最多可以放的蛋糕数
//输入: 3 2
//输出: 4
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int Cakes_1(vector<vector<int>> &arr)//没有找规律，暴力法，循环体过大无法通过牛客测试
{
	int ret = 0;
	double radius = 0.0;
	vector<pair<int, int>> num;
	pair<int, int> p(0, 0);
	num.push_back(p);
	
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[0].size(); j++)
		{
			size_t x = 0;
			for (x = 0; x < num.size(); x++)
			{
				radius = sqrt((num[x].first - i)*(num[x].first - i) + (num[x].second - j)*(num[x].second - j));
				if (radius == 2.0)
					break;
			}
			if (x == num.size())
			{
				pair<int, int> tmp(i, j);
				num.push_back(tmp);
				ret++;
			}
		}
	}
	
	return ret;
}

int Cakes_2(vector<vector<int>> &arr)
{
	int ret = 0;

	return ret;
}

int main()
{
	vector<vector<int>> arr;
	int w = 0;//长,列
	int h = 0;//宽,行
	cin >> w >> h;
	arr.resize(h);
	for (int i = 0; i < h; i++)
	{
		arr[i].resize(w);
	}

	cout << Cakes_1(arr) << endl;

	return 0;
}