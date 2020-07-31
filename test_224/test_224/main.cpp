#define _CRT_SECURE_NO_WARNINGS 1
//����-�������
//����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�
//
//����: 5
//���:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> arr;
	//�ȿ��ٿռ�
	arr.resize(numRows);
	for (int i = 0; i < numRows; i++)
	{
		arr[i].resize(i + 1, 0);
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == 0)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	return arr;
}

int main()
{
	vector<vector<int>>& arr = generate(5);
	for (auto i : arr)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}