#define _CRT_SECURE_NO_WARNINGS 1
//剧情触发时间
//在战略游戏中，玩家往往需要发展自己的势力来触发各种新的剧情，一个势力的主要属性有三种，分别是文明等级C, 
//资源储备R以及人口数量H，在游戏开始时(第0天)，三种属性的值均为0,随着游戏的进行，每一天玩家的三种属性都会对应的增加，
//我们用一个二维数组incr来表示每天的增加情况。这个二维数组的每个元素是一个长度为3的以为数组，
//例如[[1, 2, 1], [3, 4, 2]]表示第一天三种属性分别增加1, 2, 1，而第二天分别增加3, 4, 2.
//所有剧情的触发条件也用一个二维数组req表示，这个二维数组的每个元素是一个长度为3的一位数组，
//对于某个剧情的触发条件c[i], r[i], h[i]，如果当前C >= c[i]且R >= r[i]且H >= h[i]，则剧情会被触发
//根据所给信息，请计算每个剧情的触发时间，并以一个数组返回，如果某个剧情不会被触发，则该剧情对应的触发时间为 - 1
//输入：[[2, 8, 4], [2, 5, 0], [10, 9, 8]], [[2, 11, 3], [15, 10, 7], [9, 17, 12], [8, 1, 14]]
//输出：[2, -1, 3, -1]

#include <iostream>
#include <vector>
using namespace std;

vector<int> fun(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	vector<int> ret;
	if (arr1.size() == 0 || arr2.size() == 0)
		return ret;
	ret.resize(arr2.size(), -1);
	int c = 0, r = 0, h = 0;
	for (int i = 0; i < arr1.size(); i++)
	{
		c += arr1[i][0];
		r += arr1[i][1];
		h += arr1[i][2];
		for (int j = 0; j < arr2.size(); j++)
		{
			if (arr2[j][0] == 0 && arr2[j][1] == 0 && arr2[j][2] == 0)
				ret[j] = 0;
			else if (c >= arr2[j][0] && r >= arr2[j][1] && h >= arr2[j][2]&&ret[j]==-1)
				ret[j] = i + 1;
		}
	}
	return ret;
}

void main()
{
	vector<vector<int>> arr1 = { { 2, 8, 4 }, { 2, 5, 0 }, { 10, 9, 8 } };
	vector<vector<int>> arr2 = { { 2, 11, 3 }, { 15, 10, 7 }, { 9, 17, 12 }, { 8, 1, 14 } };

	vector<int> ret = fun(arr1, arr2);
	for (auto e : ret)
		cout << e << " ";
	cout << endl;
}