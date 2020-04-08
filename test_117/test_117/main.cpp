#define _CRT_SECURE_NO_WARNINGS 1
//抽卡
//时间限制：C / C++语言 1000MS；其他语言 3000MS
//内存限制：C / C++语言 131072KB；其他语言 655360KB
//题目描述：抽卡是一类类似于博弈的游戏。现在有一种抽卡方式，描述如下：
//初始你只有一次抽卡机会。每次抽卡浪费一次抽卡机会，获得一张卡片。这张卡片上有两个数字，
//第一个数字代表你能获得的钱，第二个数字代表你能获得的额外抽卡次数。额外的抽卡次数是可以累计的。
//现在，你知道了卡片的数量，所有的卡片上的数字，以及所有卡片的顺序。你只需要安排一种抽卡顺序，使得你能获得钱数最多。
//输入:第一个行一个数n, 代表卡片的数量。 接下来n行，每行用两个数ai, bi描述一张卡片。ai表示抽这张卡能获得的钱数，
//     bi表示抽这张卡能获得的额外抽卡次数。
//输出:一行一个数，代表你能获得的最多钱数。
//样例输入
//5
//0 2
//1 1
//1 0
//1 0
//2 0
//样例输出
//4
//提示
//对于100%的数据，0≤a_i, b_i≤1000, 1≤n≤1000
//样例解释：按顺序抽第2, 1, 5, 4张卡

#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int> &arr1, vector<int> &arr2)
{
	int count = 1;//抽卡次数
	int ret = 0;
	while (count)
	{
		int max = arr2[0];
		int j = 0;
		for (size_t i = 1; i < arr2.size(); i++)
		{
			if (max < arr2[i])
			{
				max = arr2[i];
				j = i;
			}
		}
		if (max != 0)
		{
			count += max;
			ret += arr1[j];
			arr1[j] = 0;
			arr2[j] = 0;
		}
		else
		{
			int max2 = arr1[0];
			int x = 0;
			for (size_t i = 1; i < arr1.size(); i++)
			{
				if (max2 < arr1[i])
				{
					max2 = arr1[i];
					x = i;
				}
			}
			ret += arr1[x];
			arr1[x] = 0;
		}

		count--;
	}
	return ret;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> arr1, arr2;
		for (int i = 0; i < n; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			arr1.push_back(a);
			arr2.push_back(b);
		}
		cout << fun(arr1, arr2) << endl;
	}

	return 0;
}