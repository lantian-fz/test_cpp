#define _CRT_SECURE_NO_WARNINGS 1
//iNOC��Ʒ�� - ������ǵı���
//          1
//       1  1  1
//     1  2  3  2  1
//  1 3 6  7  6  3  1
// 1 4 10 16 19  16 10  4  1
//1 5 15 30 45 51 45 30 15 5 1
//���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����
//3����֮�ͣ����������ĳ��������Ϊ��������0����
//���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
//�������� : ����һ��int����  ����n(n <= 1000000000)
//������� :������ص�intֵ
//����: 4
//���: 3
#include <iostream>
#include <vector>
using namespace std;

int Print_1(int n)
{
	if (n < 3)
		return -1;
	else if (n % 2 == 1)
		return 2;
	else if (n % 4 == 0)
		return 3;
	else
		return 4;
}

int Print_2(int n)
{
	vector<vector<int>> arr(n, vector<int>(2 * n - 1, 0));
	arr[0][n - 1] = arr[n - 1][0] = arr[n - 1][2 * n - 2] = 1;//���Ե��Ϊ1
	if (n < 3)
		return -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < 2 * n - 2; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1];
		}
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (arr[n - 1][i] != 0 && arr[n - 1][i] % 2 == 0)
			return i + 1;
	}
	return -1;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << Print_2(n) << endl;

	return 0;
}