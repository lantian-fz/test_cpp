#define _CRT_SECURE_NO_WARNINGS 1
//��������
//�������������������xcopy /s c:\ d:\��
//�����������£�����1��������xcopy    ����2���ַ���/s     ����3���ַ���c:\    ����4 : �ַ���d:\
//���дһ��������������ʵ�ֽ������и�����������������
//��������1.�����ָ���Ϊ�ո�
//          2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ���������
//����������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ����
//�ַ���C : \program files��������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//		  3.����������
//		  4.������������֤��������ֲ�����Ҫ�������
//�������� :����һ���ַ����������пո�
//������� :��������������ֽ��Ĳ�����ÿ����������ռһ��
//���룺 xcopy / s c : \\ d:\\
//����� 4
//       xcopy
//       /s
//       c:\\
//       d:\\

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Print(string &str)
{
	vector<string> arr;
	auto it_s = str.begin();
	while (it_s != str.end())
	{
		auto it_tmp = it_s;
		if (*it_s != '"')
		{
			while (it_s!=str.end() && *it_s != ' ')
				it_s++;
			string tmp(it_tmp, it_s);
			arr.push_back(tmp);
			if (it_s != str.end())
				it_s++;
			else
				break;
		}
		else
		{
			it_s++;
			while (/*it_s != str.end() && */*it_s != '"')
				it_s++;
			//it_s--;
			it_tmp++;
			string tmp(it_tmp, it_s);
			arr.push_back(tmp);
			it_s++;
			if (it_s != str.end())
				it_s++;
			else
				break;
		}
	}
	cout << arr.size() << endl;
	for (size_t i = 0; i<arr.size(); i++)
		cout << arr[i] << endl;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		Print(str);
	}


	return 0;
}