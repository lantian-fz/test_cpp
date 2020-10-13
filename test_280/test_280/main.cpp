#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

bool fun(int m)
{
	string s = to_string(m);
	set<char> st(s.begin(), s.end());
	if (st.size() != 1)
		return false;
	if (*st.begin() != '1')
		return false;
	return true;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n % 2 == 0 || n % 5 == 0||n<=0||n>=10000)
			continue;
		int c = 1;
		int m = 0;
		do
		{
			m = c*n;
			c++;
			if (m % 10 != 1)
				continue;
			if (fun(m))
				break;
		} while (1);
		cout << to_string(m).size() << endl;
	}

	return 0;
}
