#define _CRT_SECURE_NO_WARNINGS 1
//��������
//һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�����
//��С����������һ���ܴӻ������о����ܼ�������С�������أ�
//�������� :��������������ݡ�ÿ�����ݰ��������ַ���s, t���ֱ��ǳɶԳ��ֵĻ�������С�������䲼�������ÿ�
//	      ��ASCII�ַ���ʾ�ģ��ɼ���ASCII�ַ��ж��ٸ��������Ļ���Ҳ�ж����ֻ�������������С�������ᳬ��1000���ַ�����
//������� :��Ӧÿ�����룬����ܴӻ��Ʋ��м��������С�������������һ�鶼û�У��Ǿ����0��ÿ�����ռһ�С�
//����
//abcde a3
//aaaaaa aa
//���
//0
//3

#include <iostream>
#include <string>
using namespace std;

int fun(string &s, string &t)
{
	int ret = 0;
	auto it = s.begin();
	while (it != s.end())
	{
		string tmp(it, s.end());
		int f = tmp.find(t);
		if (f == -1)
			break;
		ret++;
		it += (f+t.size());
	}
	return ret;
}

int main()
{
	string s, t;
	while (cin >> s >> t)
		cout << fun(s, t) << endl;

	return 0;
}