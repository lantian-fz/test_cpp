#define _CRT_SECURE_NO_WARNINGS 1
//������Ϸ
//ʱ�����ƣ�C / C++���� 1000MS���������� 3000MS
//�ڴ����ƣ�C / C++���� 65536KB���������� 589824KB
//��Ŀ������
//Cassidy��Eleanore��һ�Ժ����ѣ����Ǿ�����һ������Ϸ��ĳһ����������һ��������Ϸ��
//��Ϸ�����������ģ�����һ��������Сд��ĸ���ַ���S����ÿһ���˵Ļغ��У����ǻ��������������
//1. ����������������ַ�����������԰�����ַ������гɻ����ַ�������������ʤ��
//2. �������Ǳ���ɾ���ַ����е�һ���ַ���
//��֪��Cassidy���֣��������˶���ȡ��Ѳ��Ե�����£�˭���Ի�ʤ��
//����
//�����һ�н�����һ��������t����ʾ����������(t <= 10)
//��������t�У�ÿ����һ���ַ���S����ʾһ��������ݡ�(| S | <= 1000)
//���
//����ÿ���������һ�У����Cassidy��ʤ�������Cassidy���������Eleanore
//��������
//2
//aba
//ab
//�������
//Cassidy
//Eleanore

#include <iostream>
#include <string>
using namespace std;

void fun(string &str)
{
	int arr[256] = { 0 };
	for (size_t i = 0; i < str.size(); i++)
		arr[str[i]]++;
	int n = 0;
	string s;
	while (1)
	{
		if (n % 2 == 0)
			s = "Cassidy";
		else
			s = "Eleanore";
		n++;
		int count = 0;
		int x = 0;
		for (int i = 0; i < 256; i++)
		{
			if (arr[i]%2==1)
			{
				count++;
				x = i;
			}
		}
		if (count == 1||count == 0)
		{
			cout << s << endl;
			return;
		}
		else
		{
			arr[x]--;
		}
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		while (n)
		{
			string str;
			cin >> str;
			fun(str);
			n--;
		}
	}

	return 0;
}