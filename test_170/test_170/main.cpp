#define _CRT_SECURE_NO_WARNINGS 1
//����-26.ɾ�����������е��ظ���
//����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
//ʾ�� 1:
//�������� nums = [1, 1, 2],
//����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 2:
//���� nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	if (nums.size() <= 1)
		return nums.size();
	int index = 0;
	int tmp = 0;
	for (size_t i = 1; i < nums.size(); i++)
	{

	}
}

int main()
{
	vector<int> arr = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	cout << removeDuplicates(arr) << endl;
	

	return 0;
}