#define _CRT_SECURE_NO_WARNINGS 1
//�������
//nowcoderҪ�����ѽ���һЩ���е���Ϣ���������ĵ绰����ȡ������Ҫ����Щ������Ϣ���л�����
//�����������м����һЩ����ķ��ţ�������������һ�����롣
//���������æ����һ����򣬽�����nowcoder�Ƕ����յ�����Ϣ����ȡ���м����õ���Ϣ��
//�������� :�����ж��С�ÿһ����һ�ξ������ܵ���Ϣ�����п��ܰ����ո񣩣�����ԭʼ��Ϣ���Ȳ�ȷ����
//������� :���ÿ����Ϣ��������Ϣ��
//����
//$Ts!47 & *s456  a23* +B9k
//���
//47456239

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				cout << str[i];
		}
		cout << endl;
	}

	return 0;
}