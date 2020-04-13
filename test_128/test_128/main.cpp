#define _CRT_SECURE_NO_WARNINGS 1
//mkdir
//�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin����
//����Ҫ�˴δ�����/usr������/usr/local���Լ���/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ� -p��ѡ�
//ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼��
//���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����
//�������� :��������������ݡ�ÿ�����ݵ�һ��Ϊһ��������n(1��n��1024)��
//          ������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200���ַ���
//������� :��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������ġ�mkdir -p�����ÿ������֮�����һ��������Ϊ�ָ���
//����
//3
///a
///a/b
///a/b/c
//3
///usr/local/bin
///usr/bin
///usr/local/share/bin
//���
//mkdir - p /a/b/c
//
//mkdir - p /usr/bin
//mkdir - p /usr/local/bin
//mkdir - p /usr/local/share/bin

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<string> arr(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end());//���ֵ�������
		
		for (int i = 1; i < n; i++)
		{
			if (arr[i - 1] == arr[i])
				flag[i - 1] = false;
			else if (arr[i - 1] == arr[i].substr(0, arr[i - 1].size())
				&& arr[i][arr[i - 1].size()] == '/')
				flag[i - 1] = false;
		}
		for (int i = 0; i < n; i++)
		{
			if (flag[i])
				cout << "mkdir -p " << arr[i] << endl;
		}
		cout << endl;
	}

	return 0;
}