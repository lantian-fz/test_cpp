#define _CRT_SECURE_NO_WARNINGS 1
//Ϳɫ
//СA����ѧ���������ڣ��߸��Ѿ������ˣ�ֻʣ��Ϳɫ�����ˡ�����СA���֣��������ϲ����ˡ�
//ÿһ��������Ϳһ��ɫ�飬ÿһ��ɫ�����ɫ�����Ⱦ������˵ġ� �������ϲ�����СAֻ�ܾ���������Ϳɫ��
//���һ��ɫ��û�������ϣ��Ͳ���Ϳɫ�����ڣ����㻭����Ҫ��ɫ����ɫ����СA���������е����ϣ��������СA��Ϳ���ٸ�ɫ�顣
//
//����������������������ַ���������������д��ĸ��ÿһ����ĸ����һ����ɫ��
//          ��һ���ַ���S����СA���ϵ����ϣ��ڶ����ַ���T��������Ҫ�����ϡ�   1�� | S | , | T | ��1000
//����������������һ�������������Ϳ���ٸ�ɫ�顣
//
//��������
//AAB
//ABC
//�������
//2
//��ʾ��СAӵ������A���ϣ�һ��B���ϣ�����һ��A����һ��B���ϣ��ܹ�Ϳ������ɫ�顣

#include <iostream>
#include <string>
using namespace std;

int Fun(string& s1, string& s2)
{
	int ret = 0;
	int arr1[27] = { 0 };
	int arr2[27] = { 0 };
	for (int i = 0; i < s1.size(); i++)
		arr1[s1[i] - 65]++;
	for (int i = 0; i < s2.size(); i++)
		arr2[s2[i] - 65]++;
	for (int i = 0; i < 27; i++)
	{
		if (arr1[i]>arr2[i])
			ret += arr2[i];
		else 
			ret += arr1[i];
	}
	return ret;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << Fun(s1, s2) << endl;

	return 0;
}