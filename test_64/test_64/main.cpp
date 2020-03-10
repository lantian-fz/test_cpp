#define _CRT_SECURE_NO_WARNINGS 1
//�������򷽷�
//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 
//1.�����ַ������ֵ������� ���磺"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ�������   ���磺"car" < "cats" < "koala" < "doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
//�������� :�����һ��Ϊ�ַ�������n(n �� 100),��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ���
//������� :�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
//������ݳ������ж������ֵ����������"lengths",������ַ�ʽ���������"both"���������"none"
//����: 3
//      a
//      aa
//      bbb
//���: both
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

string StrSort(vector<string> &arr)
{
	int abc = 1;
	int len = 0;

	size_t i = 0;
	for (i = arr.size() - 1; i > 0; i--)
	{
		if (arr[i].size() < arr[i - 1].size())
			break;
	}
	if (i == 0)
		len = 1;

	for (i = 0; i<arr.size() - 1; i++)
	{
		if (strcmp(arr[i].c_str(), arr[i + 1].c_str())>0)
		{
			abc = 0;	
			break;
		}
	}

	if (abc == 0 && len == 0)
		return "none";
	else if (abc == 1 && len == 0)
		return "lexicographically";
	else if (abc == 0 && len == 1)
		return "lengths";
	else
		return "both";
}

int main()
{
	int n = 0;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		arr.push_back(s);
	}

	cout << StrSort(arr) << endl;

	return 0;
}