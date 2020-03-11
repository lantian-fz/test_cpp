#define _CRT_SECURE_NO_WARNINGS 1
//井字棋
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为 - 1代表是对方玩家的棋子。
//测试样例：[[1,  0,  1], 
     //      [1, -1, -1], 
	       //[1, -1, 0]]
//返回：true
#include <iostream>
#include <vector>
using namespace std;

#define COL 3
#define ROW 3

bool checkWon(vector<vector<int> > board) 
{
	for (size_t i = 0; i < board.size(); i++)
	{
		if ((board[i][0] + board[i][1] + board[i][2]) == 3)
			return true;
	}
	for (size_t i = 0; i < board[0].size(); i++)
	{
		if ((board[0][i] + board[1][i] + board[2][i]) == 3)
			return true;
	}
	if ((board[0][0] + board[1][1] + board[2][2]) == 3)
		return true;
	if (board[0][2] + board[1][1] + board[2][0] == 3)
		return true;
	return false;
}

int main()
{
	//vector<vector<int>> board(COL, vector<int>(ROW, 0));
	vector<vector<int>> board(COL, vector<int>(ROW, 0));
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			int tmp = 0;
			cin >> tmp;
			//board[i][j] = tmp;
			board[i].push_back(tmp);
		}
	}

	return 0;
}

//int func(int x){
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x&(x - 1);//与运算
//	}
//	return count;
//}

//int main()
//{
//	cout << func(9999) << endl;
//
//	return 0;
//}