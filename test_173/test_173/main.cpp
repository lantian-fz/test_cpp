#define _CRT_SECURE_NO_WARNINGS 1
//牛客-进制转换
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//输入描述 :输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
//输出描述 :为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
//输入
//7 2
//输出
//111

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void NSystem(int m, int n)
{
	int tmp = 0;
	string s;
	bool flag = true;
	if (m == 0)//0的其他进制还是0
	{
		s.push_back('0');
		return;
	}
	while (m)
	{
		if (m<0)
		{
			m = -m;//先将m当成正数来处理
			flag = false;
		}
		if (m%n > 9)
			tmp = (m%n - 10 + 'A');//参考16进制，超过9用字母表示
		else
			tmp = m%n + '0';
		s.push_back(tmp);
		m /= n;
	}
	if (flag == false)
		s.push_back('-');

	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	int m = 0, n = 0;
	while (cin>>m>>n)
		NSystem(m, n);


	return 0;
}
