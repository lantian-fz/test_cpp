#define _CRT_SECURE_NO_WARNINGS 1
//����������
//��C / C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ�������ʣ�
//���硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
//�������� :��������������ݡ�ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100��
//������� :��Ӧÿһ�����ݣ������������Ӧ��������������
//����
//hello_world
//nice_to_meet_you
//���
//helloWorld
//niceToMeetYou

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string ret;
		int flag = 0;
		for (size_t i = 0; i<s.size(); i++)
		{
			if (s[i] == '_')
			{
				flag = 1;
				continue;
			}
			if (flag == 0)
				ret += s[i];
			else
				ret += s[i] - 32;
			flag = 0;
		}
		cout << ret << endl;
	}

	return 0;
}