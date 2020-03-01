#define _CRT_SECURE_NO_WARNINGS 1
//牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,
//一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如:一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
//     一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
//     一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
//为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示:
//如果牛牛把6个队员划分到两个队伍
//如果方案为:    team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
//而如果方案为:  team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
//没有比总和为10更大的方案,所以输出10.
//输入描述:输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
//第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10^9),表示每个参赛选手的水平值.
//输出描述:输出一个整数表示所有队伍的水平值总和最大值.
//示例1输入输出示例仅供调试，后台判题数据一般不包含示例
//输入
//2
//5 2 8 5 1 5
//输出 10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ONE 3

long LevelValue(vector<int> &arr,int n)
{
	long max = 0;
	sort(arr.begin(),arr.end());
	//每次从第二大开始加
	for (int i = n; i < n*ONE - 1; i += 2)
		max += arr[i];
	
	return max;
}

void main()
{
	int n = 0;//队伍数
	cin >> n;
	int num = n * ONE;
	vector<int> arr;
	for (int i = 0; i < num; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}
	cout << LevelValue(arr, n) << endl;
}