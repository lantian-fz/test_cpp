#define _CRT_SECURE_NO_WARNINGS 1
//牛客-手套
//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，
//所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，
//然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
//给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right, 分别代表每种颜色左右手手套的数量。
//数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
//
//测试样例：4, [0, 7, 1, 6], [1, 5, 0, 6]
//返回：10(解释：可以左手手套取2只，右手手套取8只)

//链接：https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8
//来源：牛客网
//
//对于非0递增序列(a1 < a2 < a3 < ... < an)如何覆盖每一个种类呢？
//举一个小例子：在2 3 4 5的序列中任意找三个数求和，保证没有其他的三个数的和大于它，你肯定会选择3，4，5；
//那如果需要找一个整数比其中任意三个数的和都大，且为最小的一个，应该怎么选？
//答案为：（（2 + 3 + 4 + 5） - 2） + 1 即可保证序列中任取三个数不可能比它大，且为符合条件的最小值。
//覆盖(a1, a2, ...an)的数为(sum(a1, a2, ..., an) - a1) + 1;// a1的值为最小值
//1. 题目中存在最差情况为，一边没有，这时候需要将此种颜色所有的手套带走才可以保证题意。
//2. 第二中情况就是上面的例子所体现的情况，在左右两边分别找出能够覆盖全部颜色的最小数量
//3. 判断左右两边那一边需要拿的数量最小就拿那一边，然后在另一边随便拿一个就能保证题意。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) 
{
	int sum = 0;
	int leftsum = 0, rightsum = 0;
	int leftmin = 27, rightmin = 27;
	for (int i = 0; i < n; i++)
	{
		if (left[i] * right[i] == 0)
			sum += (left[i] + right[i]);
		else
		{
			leftsum += left[i];
			rightsum += right[i];
			leftmin = min(leftmin, left[i]);
			rightmin = min(rightmin, right[i]);
		}
	}
	return sum + min(leftsum - leftmin + 1, rightsum - rightmin + 1) + 1;
}

int main()
{
	vector<int> left = { 0, 7, 1, 6 };
	vector<int> right = { 1, 5, 0, 6 };
	cout << findMinimum(4, left, right) << endl;

	return 0;
}