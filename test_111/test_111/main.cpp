#define _CRT_SECURE_NO_WARNINGS 1
//�ֽ�����
//��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an, 
//���� 1 < a1 �� a2 �� a3 �� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��������ֽ������ӡ�
//�������� :��������������ݣ�ÿ�����ݰ���һ��������a��2��a��1000000����
//������� :��Ӧÿ�����ݣ��ԡ�a = a1 * a2 * a3...������ʽ�����ʽ�ֽ��Ľ����
//���룺10
//      18
//�����10 = 2 * 5
//      18 = 2 * 3 * 3

#include <iostream>
#include <vector>
using namespace std;

void NowCoder(int n)
{
	int ret = n;
	vector<int> arr;
	int x = 2;//����

	while (x <= n)
	{
		if (n%x == 0)
		{
			while (n%x == 0)
			{
				n /= x;
				arr.push_back(x);
			}
		}
		x++;
	}
	cout << ret << " = " << arr[0] ;
	for (size_t i = 1; i < arr.size(); i++)
		cout << " * "<< arr[i];
	cout << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
		NowCoder(n);

	return 0;
}