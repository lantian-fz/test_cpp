#define _CRT_SECURE_NO_WARNINGS 1
//力扣-64.最小路径和
//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
//示例:
//输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。

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