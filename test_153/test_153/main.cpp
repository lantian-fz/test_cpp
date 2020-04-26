#define _CRT_SECURE_NO_WARNINGS 1
//左右最值最大差
//对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。
//给定int矩阵mat, 以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。
//测试样例：[[1, 2], [3, 4]], 2, 2
//返回：[1, 2, 4, 3]

#include <iostream>
#include <vector>
using namespace std;

vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) 
{
	int row = 0, col = 0;
	int rrow = n - 1 , ccol = m - 1;
	vector<int> arr;
	while (1)
	{
		for (int i = col; i <= ccol; i++)
			arr.push_back(mat[row][i]);
		row++;
		for (int i = row; i <= rrow; i++)
			arr.push_back(mat[i][ccol]);
		ccol--;
		for (int i = ccol; i >= col; i--)
			arr.push_back(mat[rrow][i]);
		rrow--;
		for (int i = rrow; i >= row; i++)
			arr.push_back(mat[i][col]);
		col++;
	}
	return arr;
}

int main()
{
	vector<vector<int>> arr = { { 1, 2 }, { 3, 4 } };
	int n = 2, m = 2;
	vector<int> ret = clockwisePrint(arr, n, m);
	for (size_t i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";

	return 0;
}