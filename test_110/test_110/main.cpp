#define _CRT_SECURE_NO_WARNINGS 1
//���Ӹ���
//һ�����������Էֽ��һ����������Ļ�������36 = 2 * 2 * 3 * 3��������2��3�������ӡ�
//NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��һ���������ÿ�������������Ӹ�����
//�������� :��������������ݡ�ÿ�����ݽ���һ������n(2��n��100000)��
//������� :��Ӧÿ����������������Ӹ�����ÿ�����ռһ�С�
//���룺30
//      26
//      20
//�����3
//      2
//      2

#include <iostream>
#include <math.h>
using namespace std;

void NowCoder(int n)
{
	int ret = 0;
	int x = 2;//����

	while (x <= sqrt(n))
	{
		if (n%x == 0)
		{
			while (n%x == 0)
				n /= x;
			ret++;
		}
		x++;
	}
	if (n != 1)
		ret++;
	cout << ret << endl;
}

int main()
{
	int n = 0;
	while (cin >> n)
		NowCoder(n);

	return 0;
}