#define _CRT_SECURE_NO_WARNINGS 1
//�ռ����б�
//NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮��
//����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
//���ڸ���һ���ռ����������������������Ӧ���ռ����б�
//�������� :��������������ݡ�ÿ�����ݵĵ�һ����һ������n(1��n��128)����ʾ������n��������
//          ������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���
//������� :��Ӧÿһ�����룬���һ���ռ����б�
//����
//3
//Joe
//Quan, William
//Letendre, Bruce
//2
//Leon
//Kewell
//���
//Joe, "Quan, William", "Letendre,Bruce"
//Leon, Kewell

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	int j = 0;
	while (cin >> n)
	{
		j++;
		cin.get();
		string ret;
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			if (s.find(",") == -1 && s.find(" ") == -1)
			{
				ret += s;
				if (i != n - 1)
					ret+=", ";//���ź���Ҫ�пո񣬲�Ȼ�޷�ͨ��ţ��ȫ������
			}
			else
			{
				ret += '\"';
				ret += s;
				if (i == n - 1)
					ret += '\"';
				else
					ret += "\", ";
			}
		}
		//cout << ret << endl;
		if (j == 1)
			cout << ret;
		else
			cout << endl << ret;
	}

	return 0;
}

//void fun(vector<string> &arr)
//{
//	string ret;
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		int x = arr[i].find(",");
//		int y = arr[i].find(" ");
//		if (x == -1 && y == -1)
//		{
//			ret += arr[i];
//			if (i != arr.size()-1)
//				ret += ",";
//		}
//		else
//		{
//			ret += "\"";
//			ret += arr[i];
//			if (i == arr.size() - 1)
//				ret += "\"";
//			else
//				ret += "\",";
//		}
//	}
//	cout << ret << endl;
//}
//
//int main()
//{
//	int n = 0;
//	int j = 0;
//	while (cin >> n)
//	{
//		vector<string> arr;
//		cin.get();
//		for (int i = 0; i < n;i++)
//		{
//			string s;
//			getline(cin, s);
//			arr.push_back(s);
//		}
//		fun(arr);
//	}
//
//	return 0;
//}