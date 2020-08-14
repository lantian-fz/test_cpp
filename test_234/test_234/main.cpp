#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-二叉树的深度

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//递归遍历的方法
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return (left>right) ? (left + 1) : (right + 1);
}

//层次遍历
int TreeDepth_2(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	queue<TreeNode*> que;
	que.push(pRoot);
	int depth = 0;
	while (!que.empty())
	{
		int sz = que.size();//每一层结点个数
		depth++;
		//一次处理一层
		for (int i = 0; i < sz; i++)
		{
			TreeNode* node = que.front();
			que.pop();
			if (node->left)
				que.push(node->left);
			if (node->right)
				que.push(node->right);
		}
	}
	return depth;
}

void main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	cout << TreeDepth(root) << endl;
	cout << TreeDepth_2(root) << endl;
}