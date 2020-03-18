#define _CRT_SECURE_NO_WARNINGS 1
//手套
//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，
//所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，
//然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
//给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right, 分别代表每种颜色左右手手套的数量。
//数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
//测试样例：4, [0, 7, 1, 6], [1, 5, 0, 6]
//返回：10(解释：可以左手手套取2只，右手手套取8只)
#include <iostream>
#include <vector>
using namespace std;

//1. 先把手套为0（匹配肯定不成功的）的这种最坏情况全部拿出来
//2. 找出两个数组中最小和（不包括0手套的）数组，把该数组中最大的手套依次全拿了，剩下最小的，拿一个
//3. 再从多的数组中，拿出随便一个，就可以匹配
//int findMinimum(int n, vector<int> left, vector<int> right) 
//{
//	// write code here
//	int min = 0, lmin = 0, rmin = 0;
//	int lm = 26, rm = 26;
//	for (int i = 0; i < n; i++)
//	{
//		if (left[i] == 0 || right[i] == 0)
//		{
//			min += left[i];
//			min += right[i];
//		}
//		else
//		{
//			lmin += left[i];
//			rmin += right[i];
//			if (left[i] < lm)
//				lm = left[i];
//			if (right[i] < rm)
//				rm = right[i];
//		}
//	}
//	min += lmin > rmin ? (rmin - rm) : (lmin - lm);
//	return min + 2;
//}
int findMinimum(int n, vector<int> left, vector<int> right) 
{
	
}

int main()
{
	

	return 0;
}