#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-二叉树中和为某一值的路径
//输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
{

}
void main()
{

}