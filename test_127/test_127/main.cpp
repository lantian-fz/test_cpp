#define _CRT_SECURE_NO_WARNINGS 1
//���ݿ����ӳ�
//Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ�
//���յ����󣬲������ӳ���û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�
//�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�
//�������� :��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000������ʾ�����������
//          ������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����
//������� :��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�
//����
//6
//A connect
//A disconnect
//B connect
//C connect
//B disconnect
//C disconnect
//���
//2

#include <iostream>
#include <string>
using namespace std;
//connect��disconnect������ȣ���ʵ������connect�������ֵĴ���
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int x = 0, max = 0;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (b == "connect")
				x++;
			else
				x--;
			if (max < x)
				max = x;
		}
		cout << max << endl;
	}

	return 0;
}