//MP3光标位置
//MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。
//为了简化处理，假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。
//现在要实现通过上下键控制光标移动来浏览歌曲列表，控制逻辑如下：
//歌曲总数 <= 4的时候，不需要翻页，只是挪动光标位置。
//光标在第一首歌曲上时，按Up键光标挪到最后一首歌曲；光标在最后一首歌曲时，按Down键光标挪到第一首歌曲。
//其他情况下用户按Up键，光标挪到上一首歌曲；用户按Down键，光标挪到下一首歌曲。
//2. 歌曲总数大于4的时候（以一共有10首歌为例）：
//特殊翻页：屏幕显示的是第一页（即显示第1 – 4首）时，光标在第一首歌曲上，用户按Up键后，屏幕要显示
//          最后一页（即显示第7 - 10首歌），同时光标放到最后一首歌上。同样的，屏幕显示最后一页时，
//		  光标在最后一首歌曲上，用户按Down键，屏幕要显示第一页，光标挪到第一首歌上。
//一般翻页：屏幕显示的不是第一页时，光标在当前屏幕显示的第一首歌曲时，用户按Up键后，屏幕从当前歌曲的
//          上一首开始显示，光标也挪到上一首歌曲。光标当前屏幕的最后一首歌时的Down键处理也类似。
//其他情况，不用翻页，只是挪动光标就行。
//输入说明：1 输入歌曲数量
//          2 输入命令 U或者D
//输出说明：1 输出当前列表
//          2 输出当前选中歌曲
//输入：10
//      UUUU
//输出：7 8 9 10
//      7
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fun(vector<int> &mp3, string &str)
{
	size_t n = 0;
	int x = 0;//n在一页当中的位置 1 2 3 4

	for (size_t i = 0; i < str.size(); i++)
	{
		if (n == 0 && str[i] == 'U')
			n = mp3.size() - 1, x = 4;
		else if (n == mp3.size() - 1 && str[i] == 'D')
			n = 0, x = 1;
		else if (str[i] == 'U')
		{
			n--;
			if (x != 1)
				x--;
		}
		else if (str[i] == 'D')
		{
			n++;
			if (x != 4)
				x++;
		}
	}

	if (mp3.size() <= 4)
	{
		for (size_t i = 0; i < mp3.size(); i++)
			cout << mp3[i] << " ";
		cout << endl;
	}
	else
	{
		switch (x)
		{
		case 1:cout << mp3[n] << " " << mp3[n + 1] << " " << mp3[n + 2] << " " << mp3[n + 3] << endl; break;
		case 2:cout << mp3[n - 1] << " " << mp3[n] << " " << mp3[n + 1] << " " << mp3[n + 2] << endl; break;
		case 3:cout << mp3[n - 2] << " " << mp3[n - 1] << " " << mp3[n] << " " << mp3[n + 1] << endl; break;
		case 4:cout << mp3[n - 3] << " " << mp3[n - 2] << " " << mp3[n - 1] << " " << mp3[n] << endl; break;
		}
	}
	cout << mp3[n] << endl;
}

int main()
{
	int n = 0;
	string str;
	while (cin >> n >> str)
	{
		vector<int> mp3;
		for (int i = 0; i < n; i++)
			mp3.push_back(i + 1);
		fun(mp3, str);
	}

	return 0;
}