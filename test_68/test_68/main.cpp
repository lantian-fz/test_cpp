#define _CRT_SECURE_NO_WARNINGS 1
//������
//����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
//����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ����ӡ�
//����������[[1,  0,  1], 
     //      [1, -1, -1], 
	       //[1, -1, 0]]
//���أ�true
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
//		x = x&(x - 1);//������
//	}
//	return count;
//}

//int main()
//{
//	cout << func(9999) << endl;
//
//	return 0;
//}