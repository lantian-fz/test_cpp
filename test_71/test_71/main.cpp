#define _CRT_SECURE_NO_WARNINGS 1
//求最大连续bit数
//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//输入描述:输入一个byte数字
//输出描述:输出转成二进制之后连续1的个数
//输入: 3
//输出: 2
#include <iostream>
using namespace std;

int By(int byte)
{
	int max = 0;
	int tmp = 0;
	//int byt = byte - '0';
	for (int i = 0; i < 8; i++)
	{
		if (((byte >> i) & 1) == 1)
			tmp++;
		else
			tmp = 0;

		if (max < tmp)
			max = tmp;
	}
	return max;
}

int main()
{
	int byte = 0;
	while (cin >> byte)
		cout << By(byte) << endl;

	return 0;
}