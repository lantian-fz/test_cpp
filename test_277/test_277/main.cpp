#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
//AAAB1ccb5

bool cmp(pair<char, int>& a, pair<char, int> &b)
{
	//if (a.second == b.second)
	//	return a.first < b.first;
	//else
	//	return a.second > b.second;
	return a.second == b.second ? a.first<b.first : a.second>b.second;
}

string printOutput(string input) 
{
	if (input.empty())
		return input;
	string ret;
	map<char, int> mp;
	for (auto e : input)
	{
		if (e >= 'a'&&e <= 'z' || e >= 'A'&&e <= 'Z')
			mp[e]++;
	}
	vector<pair<char,int>> arr;
	for (auto e : mp)
		arr.push_back(e);
	sort(arr.begin(), arr.end(),cmp);

	for (auto e : arr)
		ret += e.first + to_string(e.second);
	
	return ret;
}

int main()
{
	string s;
	while (cin >> s)
		cout << printOutput(s) << endl;

	return 0;
}