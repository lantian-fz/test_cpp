#define _CRT_SECURE_NO_WARNINGS 1
//�˿��ƴ�С
//�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С������
//�����ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ��������
//3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
//���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���"-"����û�пո��磺4 4 4 4 - joker JOKER��
//��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR��
//��������
//��1������ÿ���ƿ����Ǹ��ӡ����ӡ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣����������������
//	 �����뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
//��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ
//	���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ���
//��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӡ����ӡ������Ƚ������С��˳�ӱȽ���С�ƴ�С��
//	 ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
//��4������������Ʋ��������ȵ������
//��������:���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���"-"����û�пո��� 4 4 4 4-joker JOKER��
//������� :����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��
//����: 4 4 4 4-joker JOKER
//���: joker JOKER
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Sepparation(vector<vector<string>> &ar, string &str)//����ո�
{
	auto it = str.begin();
	vector<string> arr1;
	vector<string> arr2;
	while (*it != '-')
	{
		auto x = it;
		while (*it != '-' && *it != ' ')
			it++;
		string tmp(x, it);
		arr1.push_back(tmp);
		if (*it == '-')
			break;
		it++;
	}
	ar.push_back(arr1);
	it++;
	while (it != str.end())
	{
		auto x = it;
		while (it != str.end() && *it != ' ')
			it++;
		string tmp(x, it);
		arr2.push_back(tmp);
		if (it != str.end())
			it++;
	}
	ar.push_back(arr2);
}

int PlayingCardKind(vector<string> &str)//�ж��Ƶ�����
{
	if (str.size() == 1)
		return 0;//����
	if (str.size() == 2)
	{
		if (str[0] == string("joker") || str[1] == string("joker"))
			return 5;//����
		else
			return 1;//��ͨ����
	}
	if (str.size() == 3)
		return 2;//����
	if (str.size() == 4)
		return 3;//ը��
	if (str.size() == 5)
		return 4;//˳��
	return 0;
}

void PlayingCard(string& str)
{
	string er("ERROR");
	vector<vector<string>> ar;
	int count = -1;//0Ϊ���ܱȽϣ�1Ϊ��һ���ƣ�2Ϊ�ڶ�����
	//ͨ���±�����ж��ƵĴ�С
	vector<string> s = { "3", "4", "5", "6", "7", "8", "9", "10",
						 "J", "Q", "K", "A", "2", "joker", "JOKER" };
	Sepparation(ar, str);
	int flag1 = PlayingCardKind(ar[0]);
	int flag2 = PlayingCardKind(ar[1]);
	//����������ը������������
	if (flag1 == 3 || flag2 == 3 || flag1 == 5 || flag2 == 5)
	{
		if (flag1 == 5) //����ֻ��һ��
			count = 1;
		else if (flag2 == 5)
			count = 2;
		else if (flag1 == flag2&&flag1 == 3)//����ը�����Ƚ�ը����С
		{
			auto x1 = find(s.begin(), s.end(), ar[0][0]);
			auto x2 = find(s.begin(), s.end(), ar[1][0]);
			count = x1 < x2 ? 2 : 1;
		}
		else if (flag1 == 3 && flag2 != 3)
			count = 1;
		else if (flag1 != 3 && flag2 == 3)
			count = 2;
	}
	else if (flag1 == flag2)//�Ƶ�������ͬʱ
	{
		auto x1 = find(s.begin(), s.end(), ar[0][0]);
		auto x2 = find(s.begin(), s.end(), ar[1][0]);
		count = x1 < x2 ? 2 : 1;
	}
	else //���޷��Ƚ�ʱ
		count = 0;

	//���
	if (count == 0)
		cout << "ERROR" << endl;
	else
	{
		int i = 0;
		for (i = 0; i < ar[count - 1].size() - 1; i++)
			cout << ar[count - 1][i] << " ";
		cout << ar[count - 1][i] << endl;
	}
}

int main()
{
	string str;
	while (getline(cin, str))
		PlayingCard(str);

	return 0;
}