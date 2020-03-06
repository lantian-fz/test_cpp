#define _CRT_SECURE_NO_WARNINGS 1
//���ַ���ת��������
//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��
//Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
//�������� :����һ���ַ���, ����������ĸ����, ����Ϊ��
//������� :����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
//���룺 +2147483647
//       1a33
//����� 2147483647
//       0
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int StrToInt(string str) 
{
	int ret = 0;
	int i = 0;
	bool flag = true;
	if (str[0] == '-')
	{
		flag = false;
		str.erase(0, 1);
	}
	else if (str[0] == '+')
		str.erase(0, 1);
	if (str.size() == 0)
		return 0;
	while (str.size())
	{
		if (str[str.size() - 1]<'0' || str[str.size() - 1]>'9')
			return 0;
		int num = (int)pow(10, i);
		ret += (str[str.size() - 1] - '0') * num;
		str.erase(str.size() - 1, 1);
		i++;
	}
	if (flag == false)
		ret = -ret;

	return ret;
}

int main()
{
	string str;
	cin >> str;

	cout << StrToInt(str) << endl;

	return 0;
}