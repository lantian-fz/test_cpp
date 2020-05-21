#define _CRT_SECURE_NO_WARNINGS 1
//����-64.��С·����
//����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//˵����ÿ��ֻ�����»��������ƶ�һ����
//ʾ��:
//����:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//���: 7
//����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
	vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),0));
	dp[0][0] = grid[0][0];

	for (size_t i = 1; i < grid.size(); i++)
		dp[i][0] = grid[i][0] + dp[i - 1][0];
	for (size_t i = 1; i < grid[0].size(); i++)
		dp[0][i] = grid[0][i] + dp[0][i - 1];
	for (size_t i = 1; i < grid.size(); i++)
	{
		for (size_t j = 1; j < grid[0].size(); j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
	}
	return dp[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
	vector<vector<int>> arr = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
	cout << minPathSum(arr) << endl;

	return 0;
}