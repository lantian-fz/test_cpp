#define _CRT_SECURE_NO_WARNINGS 1
//力扣-56.合并区间
//给出一个区间的集合，请合并所有重叠的区间。
//示例 1:
//输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//示例 2:
//输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<vector<int>> merge_1(vector<vector<int>>& intervals) 
//{
//
//}
//排序+双指针
vector<vector<int>> merge_2(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;
	for (int i = 0; i < intervals.size();) 
	{
		int t = intervals[i][1];
		int j = i + 1;
		while (j < intervals.size() && intervals[j][0] <= t) 
		{
			t = max(t, intervals[j][1]);
			j++;
		}
		ans.push_back({ intervals[i][0], t });
		i = j;
	}
	return ans;
}
int main()
{
	vector<vector<int>> arr = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };

	vector<vector<int>> p = merge_2(arr);

	for (size_t i = 0; i < p.size(); i++)
	{
		for (size_t j = 0; j < p[0].size(); j++)
			cout << p[i][j] << " ";
		cout << ",";
	}

	return 0;
}