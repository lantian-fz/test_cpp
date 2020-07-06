#define _CRT_SECURE_NO_WARNINGS 1
//扑克牌大小
//扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用
//如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
//3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
//输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4 - joker JOKER。
//请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
//基本规则：
//（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，
//	 由输入保证两手牌都是合法的，顺子已经从小到大排列；
//（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系
//	（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
//（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；
//	 炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
//（4）输入的两手牌不会出现相等的情况。
//输入描述:输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如 4 4 4 4-joker JOKER。
//输出描述 :输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
//输入: 4 4 4 4-joker JOKER
//输出: joker JOKER
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Sepparation(vector<vector<string>> &ar, string &str)//分离空格
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

int PlayingCardKind(vector<string> &str)//判断牌的种类
{
	if (str.size() == 1)
		return 0;//个子
	if (str.size() == 2)
	{
		if (str[0] == string("joker") || str[1] == string("joker"))
			return 5;//对王
		else
			return 1;//普通对子
	}
	if (str.size() == 3)
		return 2;//三个
	if (str.size() == 4)
		return 3;//炸弹
	if (str.size() == 5)
		return 4;//顺子
	return 0;
}

void PlayingCard(string& str)
{
	string er("ERROR");
	vector<vector<string>> ar;
	int count = -1;//0为不能比较，1为第一幅牌，2为第二幅牌
	//通过下标可以判断牌的大小
	vector<string> s = { "3", "4", "5", "6", "7", "8", "9", "10",
						 "J", "Q", "K", "A", "2", "joker", "JOKER" };
	Sepparation(ar, str);
	int flag1 = PlayingCardKind(ar[0]);
	int flag2 = PlayingCardKind(ar[1]);
	//两副牌中有炸弹或对王的情况
	if (flag1 == 3 || flag2 == 3 || flag1 == 5 || flag2 == 5)
	{
		if (flag1 == 5) //对王只有一对
			count = 1;
		else if (flag2 == 5)
			count = 2;
		else if (flag1 == flag2&&flag1 == 3)//都是炸弹，比较炸弹大小
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
	else if (flag1 == flag2)//牌的数量相同时
	{
		auto x1 = find(s.begin(), s.end(), ar[0][0]);
		auto x2 = find(s.begin(), s.end(), ar[1][0]);
		count = x1 < x2 ? 2 : 1;
	}
	else //牌无法比较时
		count = 0;

	//输出
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