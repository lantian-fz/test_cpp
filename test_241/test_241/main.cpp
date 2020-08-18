#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�˿��Ƶ�˳��
//���ӣ�https ://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4
//��Դ��ţ����
//
//LL���������ر��, ��Ϊ��ȥ����һ���˿���, ���������Ȼ��2������, 2��С��(һ����ԭ����54��)
//��������г����5����, �����Լ�������, �����ܲ��ܳ鵽˳�ӡ�����A, ����3, С��, ����, ��Ƭ5��,
//��\С �����Կ����κ�����,����A����1, JΪ11, QΪ12, KΪ13�������5���ƾͿ��Ա�ɡ�1, 2, 3, 4, 5��
//(��С���ֱ���2��4)������, Ҫ����ʹ�������ģ������Ĺ���, Ȼ���������LL��������Σ�
//����������˳�Ӿ����true����������false��Ϊ�˷������, �������Ϊ��С����0��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsContinuous(vector<int> numbers)
{
	if (numbers.size() != 5)
		return false;
	sort(numbers.begin(), numbers.end());
	int zeros = 0;//��С���ĸ���
	while (zeros<numbers.size() && numbers[zeros] == 0)
		zeros++;
	for (int i = zeros; i < numbers.size() - 1; i++)
	{
		if (numbers[i] == numbers[i + 1])
			return false;
		zeros -= (numbers[i + 1] - numbers[i] - 1);
	}
	return zeros >= 0;
}

void main()
{
	vector<int> arr = { 1, 3, 0, 0, 5 };
	cout << IsContinuous(arr) << endl;
}