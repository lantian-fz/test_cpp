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
//��������:���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���"-"����û�пո��� 4 4 4 4 - joker JOKER��
//������� :����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��
//����: 4 4 4 4-joker JOKER
//���: joker JOKER
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//A-K ����Ϊ1-13��joker=14,JOKER=15
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
	}
	ar.push_back(arr1);
	it++;
	while (it != str.end())
	{
		auto x = it;
		while (*it != '-' && *it != ' ')
			it++;
		string tmp(x, it);
		arr2.push_back(tmp);
	}
	ar.push_back(arr2);
}
string PlayingCard(string& str)
{
	string er("ERROR");
	vector<vector<string>> ar;
	Sepparation(ar, str);


	return ar[0][0];
}

int main()
{
	string str;
	while (getline(cin,str))
		cout << PlayingCard(str) << endl;

	return 0;
}