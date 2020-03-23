#define _CRT_SECURE_NO_WARNINGS 1
//汽水瓶
//有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
//答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，
//这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
//如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
//输入描述 :输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1 <= n <= 100），
//          表示小张手上的空汽水瓶数。n = 0表示输入结束，你的程序不应当处理这一行。
//输出描述 :对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
//输入：3
//      10
//      81
//      0
//输出：1
//      5
//      40
#include <iostream>
#include <vector>
using namespace std;

vector<int> fun(vector<int> &arr)
{
	vector<int> ret;
	for (size_t i = 0; i < arr.size(); i++)
	{
		int x = arr[i];//当前空瓶数
		int n = 0;//喝掉总瓶数
		int a = 0;//当前喝掉瓶数
		while (x>1)
		{
			a = x / 3;
			n += a;
			x = a + x % 3;
			if (x == 2)
				x++;
		}
		ret.push_back(n);
	}
	return ret;
}

int main()
{
	int n = 1;
	vector<int> arr;
	while (cin >> n && n != 0)
	{
		arr.push_back(n);
	}
	vector<int> ret = fun(arr);
	for (size_t i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}