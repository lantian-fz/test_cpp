#define _CRT_SECURE_NO_WARNINGS 1
//�鿨
//ʱ�����ƣ�C / C++���� 1000MS���������� 3000MS
//�ڴ����ƣ�C / C++���� 131072KB���������� 655360KB
//��Ŀ�������鿨��һ�������ڲ��ĵ���Ϸ��������һ�ֳ鿨��ʽ���������£�
//��ʼ��ֻ��һ�γ鿨���ᡣÿ�γ鿨�˷�һ�γ鿨���ᣬ���һ�ſ�Ƭ�����ſ�Ƭ�����������֣�
//��һ�����ִ������ܻ�õ�Ǯ���ڶ������ִ������ܻ�õĶ���鿨����������ĳ鿨�����ǿ����ۼƵġ�
//���ڣ���֪���˿�Ƭ�����������еĿ�Ƭ�ϵ����֣��Լ����п�Ƭ��˳����ֻ��Ҫ����һ�ֳ鿨˳��ʹ�����ܻ��Ǯ����ࡣ
//����:��һ����һ����n, ����Ƭ�������� ������n�У�ÿ����������ai, bi����һ�ſ�Ƭ��ai��ʾ�����ſ��ܻ�õ�Ǯ����
//     bi��ʾ�����ſ��ܻ�õĶ���鿨������
//���:һ��һ�������������ܻ�õ����Ǯ����
//��������
//5
//0 2
//1 1
//1 0
//1 0
//2 0
//�������
//4
//��ʾ
//����100%�����ݣ�0��a_i, b_i��1000, 1��n��1000
//�������ͣ���˳����2, 1, 5, 4�ſ�

#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int> &arr1, vector<int> &arr2)
{
	int count = 1;//�鿨����
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