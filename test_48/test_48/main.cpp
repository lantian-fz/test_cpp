#define _CRT_SECURE_NO_WARNINGS 1
//��������������4��1 - 10�����֣�ͨ���Ӽ��˳����õ�����Ϊ24����ʤ��
//���룺4��1 - 10�����֡�[���������ظ�����ÿ�����ֽ�����ʹ��һ�Σ�����������֤���쳣����]
//�����true or false
//����4��int����
//������� :
//�����ܷ�õ�24�㣬�����true���������false
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Twenty_four(vector<int>& arr)
{
}

int main()
{
	vector<int> arr;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		cin >> tmp;

		arr.push_back(tmp);
	}

	cout << Twenty_four(arr) << endl;

	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int MAX_Arry(vector<int>& arr)
//{
//	int MAX = arr[0];
//	int sum = arr[0];
//	int i = 1;
//	if (arr.size() <= 1)
//		return 0;
//	for (i = 1; i < arr.size(); i++)
//	{
//		if (sum < 0)  //���ǰһ���������С��0��������￪ʼ�µ�������
//			sum = arr[i];
//		else
//		{
//			sum += arr[i];//�������
//		}
//		if (sum > MAX)//��¼��ÿ���������к����ʱ��ֵ
//			MAX = sum;
//	}
//	return MAX;
//}
//
//void main()
//{
//	vector<int> arr;
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x = 0;
//		cin >> x;
//		arr.push_back(x);
//	}
//	cout << MAX_Arry(arr) << endl;
//}

//void KnockoutChar(string& str1, string& str2)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//
//	for (i = 0; str1[i] != '\0'; i++)
//	{
//		for (j = 0; str2[j] != '\0'; j++)
//		{
//			if (str1[i] == str2[j])
//			{
//				for (k = i; str1[k] != '\0'; k++)
//					str1[k] = str1[k + 1];
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	string str1;
//	string str2;
//	//gets();
//	//gets();
//	str1.resize(1024);
//	//str2.size(1024);
//	cin.getline(str1);
//	
//
//	KnockoutChar(str1, str2);
//	cout << str1;
//	return 0;
//}