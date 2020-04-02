#define _CRT_SECURE_NO_WARNINGS 1
//����λ�϶�����������ż��λ�϶���ż��
//����һ�����Ȳ�С��2������arr�� дһ����������arr��ʹarr��Ҫô���е�ż��λ�϶���ż����
//Ҫô���е�����λ�϶��������ϡ� Ҫ��������鳤��ΪN��ʱ�临�Ӷ���ﵽO(N)������ռ�
//���Ӷ���ﵽO(1),�±�0,2,4,6...����ż��λ,�±�1,3,5,7...��������λ������[1,2,3,4]����Ϊ[2,1,4,3]����
#include <iostream>
#include <vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) 
{
	int i = 0;
	int j = 1;
	while (i < len && j < len)
	{
		if (arr[len - 1] % 2 == 0)
		{
			swap(arr[len - 1], arr[i]);
			i += 2;
		}
		else
		{
			swap(arr[len - 1], arr[j]);
			j += 2;
		}
	}
}

int main()
{
	int n = 0;
	vector<int> arr;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			cin >> tmp;
			arr.push_back(tmp);
		}
		oddInOddEvenInEven(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	return 0;
}