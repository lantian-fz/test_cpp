#define _CRT_SECURE_NO_WARNINGS 1
//�мٱ�
//��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬
//�����������Ǯ���мٱң�������ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ�����
//����ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����
//�������� :1��n��2 ^ 30, ����0��������
//������� :���Ҫ�Ƽ���һ���ܰ��Ǹ��ٱ��ҳ�����
//���룺3
//      12
//      0
//�����1
//      3
#include <iostream>
using namespace std;

void fun(int n)
{
	if (n == 1)
	{
		cout << "0" << endl;
		return;
	}
	if (n <= 3)
	{
		cout << "1" << endl;
		return;
	}
	int count = 1;
	while (n > 3)
	{
		if (n % 3 == 0)
			n /= 3;
		else
			n = n / 3 + 1;
		count++;
	}
	cout << count << endl;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		fun(n);

	}

	return 0;
}