#define _CRT_SECURE_NO_WARNINGS 1
//ţ��-���ַ���ת��������
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
//�������� :����һ���ַ���, ����������ĸ����, ����Ϊ��
//������� :����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
//����
//+ 2147483647
//1a33
//���
//2147483647
//0

#include <iostream>
#include <string>
using namespace std;
//δͨ��ţ�����в���
//���룺-2147483649
//�����-2147483649
//������ֵ��int�ͣ�������2147483647������������
int StrToInt(string str) 
{
	if (str.size() == 0)
		return 0;
	int i = 0;
	int flag = 1;//����flag=1������flag=-1
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] == ' ')
		i++;
	long long ret = 0;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			ret = ret * 10 + str[i] - '0';
		else
			return 0;
	}
	return (int)ret*flag;
}

int main()
{
	string s;
	while (getline(cin, s))
		cout << StrToInt(s) << endl;

	return 0;
}