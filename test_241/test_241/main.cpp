#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-扑克牌的顺子
//链接：https ://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4
//来源：牛客网
//
//LL今天心情特别好, 因为他去买了一副扑克牌, 发现里面居然有2个大王, 2个小王(一副牌原本是54张)
//他随机从中抽出了5张牌, 想测测自己的手气, 看看能不能抽到顺子“红心A, 黑桃3, 小王, 大王, 方片5”,
//大\小 王可以看成任何数字,并且A看作1, J为11, Q为12, K为13。上面的5张牌就可以变成“1, 2, 3, 4, 5”
//(大小王分别看作2和4)，现在, 要求你使用这幅牌模拟上面的过程, 然后告诉我们LL的运气如何，
//如果牌能组成顺子就输出true，否则就输出false。为了方便起见, 你可以认为大小王是0。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsContinuous(vector<int> numbers)
{
	if (numbers.size() != 5)
		return false;
	sort(numbers.begin(), numbers.end());
	int zeros = 0;//大小王的个数
	while (zeros<numbers.size() && numbers[zeros] == 0)
		zeros++;
	for (int i = zeros; i < numbers.size() - 1; i++)
	{
		if (numbers[i] == numbers[i + 1])
			return false;
		zeros -= (numbers[i + 1] - numbers[i] - 1);
	}
	return zeros >= 0;
}

void main()
{
	vector<int> arr = { 1, 3, 0, 0, 5 };
	cout << IsContinuous(arr) << endl;
}