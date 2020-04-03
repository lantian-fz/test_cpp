#define _CRT_SECURE_NO_WARNINGS 1
//有假币
//居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，
//结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量
//比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。
//输入描述 :1≤n≤2 ^ 30, 输入0结束程序。
//输出描述 :最多要称几次一定能把那个假币找出来？
//输入：3
//      12
//      0
//输出：1
//      3
#include <iostream>
using namespace std;

void fun(int n)
{
	if (n == 1)
	{
		cout << "0" << endl;
		return;
	}
	if (n <= 3)
	{
		cout << "1" << endl;
		return;
	}
	int count = 1;
	while (n > 3)
	{
		if (n % 3 == 0)
			n /= 3;
		else
			n = n / 3 + 1;
		count++;
	}
	cout << count << endl;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		fun(n);

	}

	return 0;
}