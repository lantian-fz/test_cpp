#define _CRT_SECURE_NO_WARNINGS 1
//������ֵ����
//����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�
//����int����mat, �Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������
//����������[[1, 2], [3, 4]], 2, 2
//���أ�[1, 2, 4, 3]

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