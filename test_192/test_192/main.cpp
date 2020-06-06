#define _CRT_SECURE_NO_WARNINGS 1
//����-56.�ϲ�����
//����һ������ļ��ϣ���ϲ������ص������䡣
//ʾ�� 1:
//����: [[1,3],[2,6],[8,10],[15,18]]
//���: [[1,6],[8,10],[15,18]]
//����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
//
//ʾ�� 2:
//����: [[1,4],[4,5]]
//���: [[1,5]]
//����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<vector<int>> merge_1(vector<vector<int>>& intervals) 
//{
//
//}
//����+˫ָ��
vector<vector<int>> merge_2(vector<vector<int>>& intervals) 
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;
	for (int i = 0; i < intervals.size();) 
	{
		int t = intervals[i][1];
		int j = i + 1;
		while (j < intervals.size() && intervals[j][0] <= t) 
		{
			t = max(t, intervals[j][1]);
			j++;
		}
		ans.push_back({ intervals[i][0], t });
		i = j;
	}
	return ans;
}
int main()
{
	vector<vector<int>> arr = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };

	vector<vector<int>> p = merge_2(arr);

	for (size_t i = 0; i < p.size(); i++)
	{
		for (size_t j = 0; j < p[0].size(); j++)
			cout << p[i][j] << " ";
		cout << ",";
	}

	return 0;
}