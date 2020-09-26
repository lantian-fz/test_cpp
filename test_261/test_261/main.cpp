#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
��src�еĵ�bitIndexλ��bitCountλ���Ƶ�dst��ͬλ��
******************************��ʼд����******************************/
int replaceBits(int src, int dst, int bitIndex, int bitCount) {
	int ret = 0;
	for (int i = 31; i >=0; i--)
	{
		ret <<= 1;
		if (i >= bitIndex&&i <= bitCount)
		{
			if (((src >> i) & 1) == 1)
				ret |= 1;
		}
		else if (((dst >> i) & 1) == 1)
			ret |= 1;
	}
	return ret;
}
/******************************����д����******************************/


int main() {
	int res;

	int _src;
	cin >> _src;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int _dst;
	cin >> _dst;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int _bitIndex;
	cin >> _bitIndex;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int _bitCount;
	cin >> _bitCount;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	res = replaceBits(_src, _dst, _bitIndex, _bitCount);
	cout << res << endl;

	return 0;
}
