#define _CRT_SECURE_NO_WARNINGS 1
//��Ҫ��
//����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬
//�������鵰���ŷ����þ��벻�ܵ���2������������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
//( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����,С����֪�������ԷŶ��ٿ鵰������������
//��������:ÿ������������񳤿�W,H���ÿո�ָ�.(1 �� W��H �� 1000)
//�������:���һ�������Էŵĵ�����
//����: 3 2
//���: 4
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int Cakes_1(vector<vector<int>> &arr)//û���ҹ��ɣ���������ѭ��������޷�ͨ��ţ�Ͳ���
{
	int ret = 0;
	double radius = 0.0;
	vector<pair<int, int>> num;
	pair<int, int> p(0, 0);
	num.push_back(p);
	
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[0].size(); j++)
		{
			size_t x = 0;
			for (x = 0; x < num.size(); x++)
			{
				radius = sqrt((num[x].first - i)*(num[x].first - i) + (num[x].second - j)*(num[x].second - j));
				if (radius == 2.0)
					break;
			}
			if (x == num.size())
			{
				pair<int, int> tmp(i, j);
				num.push_back(tmp);
				ret++;
			}
		}
	}
	
	return ret;
}

int Cakes_2(vector<vector<int>> &arr)
{
	int ret = 0;

	return ret;
}

int main()
{
	vector<vector<int>> arr;
	int w = 0;//��,��
	int h = 0;//��,��
	cin >> w >> h;
	arr.resize(h);
	for (int i = 0; i < h; i++)
	{
		arr[i].resize(w);
	}

	cout << Cakes_1(arr) << endl;

	return 0;
}