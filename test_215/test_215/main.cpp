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

void FindPath(TreeNode* root, int expectNumber, vector<vector<int>>& ret, vector<int>&arr, int& currentSun)
{
	currentSun += root->val;
	arr.push_back(root->val);
	if (currentSun == expectNumber&&root->left == nullptr&&root->right == nullptr)
		ret.push_back(arr);

	if (root->left != nullptr)
		FindPath(root->left, expectNumber, ret, arr, currentSun);
	if (root->right != nullptr)
		FindPath(root->right, expectNumber, ret, arr, currentSun);

	currentSun -= root->val;
	arr.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
{
	vector<vector<int>> ret;
	vector<int> arr;
	int currentSun = 0;
	FindPath(root, expectNumber, ret, arr, currentSun);
	return ret;
}

void main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(12);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(7);

	vector<vector<int>>& ret = FindPath(root, 22);

	for (auto i : ret)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}