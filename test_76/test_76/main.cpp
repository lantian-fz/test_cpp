#define _CRT_SECURE_NO_WARNINGS 1
//��ʯ��
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ��
//��ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬
//�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//���磺N = 4��M = 24��    4->6->8->12->18->24   ����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
//��������:����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)
//�������:���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1
//���룺 4 24
//����� 5

#include <iostream>
using namespace std;

int Num(int n,int count)
{
	for (int i = count - 1; i > 1; i--)
	{
		if (n%i == 0)
			return i;
	}
	return 0;
}
int ret = 0;

//int Min(int n, int m, int count)
//{
//	int x = Num(n, n);
//	if (n == m)
//		return 1;
//	else
//	{
//		if (n + x <= m)
//		{
//			Min(n + x, m, x);
//		}
//		else
//		{
//			while (n + x > m)
//			{
//				x = Num(n, x);
//			}
//		}
//	}
//}
int Min(int n, int m,int x)
{
	int tmp = 0;
	if (n == m)
		return 1;
	int count = Num(n, x);
	while (n + count < m&&count!=0)
	{
		n += count;
		count = Num(n, n);
		ret++;
	}
	tmp = Num(n,count);

	while (n + count != m&&count != 0)
	{
		count = Num(n, count);

		while (n + count < m&&count!=0)
		{
			n += count;
			count = Num(n, n);
			ret++;
		}
	}
	if (count == 0)
	{
		n -= tmp;
		x = Num(n, n);
		return Min(n, m, x) + 1;
	}
	return -1;
}
int MinNum(int n, int m)
{
	//int count = Num(n, n);//n�����Լ��
	//if (n == m)
	//	return 1;
	//else
	int count = Num(n, n);//n�����Լ��
	int r = Min(n, m, n);


	return -1;
}

int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		cout << MinNum(n, m) << endl;
	}

	return 0;
}