#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> MyToArr(string s)
{
	vector<int> ret;
	if (s.empty())
		return ret;
	int i = 0;
	while (i<s.size())
	{
		string tmp;
		while (i < s.size() && s[i] != ' ')
			tmp += s[i++];
		ret.push_back(atoi(tmp.c_str()));
		i++;
	}
	return ret;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<int> arr = MyToArr(s);
		map<int, int> mp;
		bool flag = false;
		for (auto e : arr)
		{
			mp[e]++;
			if (mp[e] > 1)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

	return 0;
}