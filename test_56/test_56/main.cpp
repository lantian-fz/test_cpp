#define _CRT_SECURE_NO_WARNINGS 1
//计算糖果
//A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
//A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
//现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
//输入描述 :输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。
//输出描述 :输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
//输入: 1 - 2 3 4
//输出:2 1 3
#include <iostream>
#include <vector>
using namespace std;

vector<int> ABCMeet(vector<int> &arr)
{
	vector<int> s;
	//s.resize(3);

	if ((arr[0] + arr[1] + arr[2] + arr[3] + 120) % 2 == 1)
		return s;

	s.resize(3);//此步很重要，放前面就会有bug

	s[0] = (arr[0] + arr[2]) / 2;
	s[1] = (arr[1] + arr[3]) / 2;
	s[2] = arr[3] - s[1];

	if (s[0] - s[1] == arr[0] && s[1] - s[2] == arr[1] && s[0] + s[1] == arr[2] && s[1] + s[2] == arr[3])
		return s;
	s.resize(0);

	return s;
}

int main()
{
	vector<int> arr;
	for (int i = 0; i < 4; i++)
	{
		int tmp = 0;
		cin >> tmp;
		if (tmp<-30 || tmp>30)
		{
			cout << "No" << endl;
			return 0;
		}
		arr.push_back(tmp);
	}
	vector<int> abc = ABCMeet(arr);
	if (abc.size()==0)
		cout << "No" << endl;
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (i < 2)
				cout << abc[i] << " ";
			else
				cout << abc[i];
		}
		cout << endl;
	}
	return 0;
}