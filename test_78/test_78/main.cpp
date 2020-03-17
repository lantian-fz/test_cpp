#define _CRT_SECURE_NO_WARNINGS 1
//���˵Ĵ���
//һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
//���磺��������������ĺ�����{1, 1, 2, 3}��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��,���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
//��������:��һ������һ��������n(n �� 1000)
//         �ڶ���Ϊn����������xi(xi �� 1000)
//�������:������Բ��������˵Ĵ�����
//���룺 3
//       1 1 1
//����� 2
#include <iostream>
#include <vector>
using namespace std;
//���� + dfs + �򵥼�֦
#include <cstdio>
#include <cstring>
#include <algorithm>
int x[1002], n;
long long ans;
long long sum, mul;
void dfs(int index)
{
	for (int i = index; i<n; i++)
	{
		sum += x[i];
		mul *= x[i];
		if (sum>mul)
		{
			ans++;
			dfs(i + 1);
		}
		else if (x[i] == 1)
		{
			dfs(i + 1);
		}
		else
		{
			sum -= x[i];
			mul /= x[i];
			break;
		}
		sum -= x[i];
		mul /= x[i];
		for (; i < n - 1 && x[i] == x[i + 1]; i++);
	}
}
int main()
{
	//freopen("1.in", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		sum = 0;
		mul = 1;
		for (int i = 0; i<n; i++)
			scanf("%d", x + i);
		std::sort(x, x + n);
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}