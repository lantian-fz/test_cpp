#define _CRT_SECURE_NO_WARNINGS 1
//二叉树的最近公共祖先

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr){}
};

int lowestCommonAncestor(TreeNode* root, int o1, int o2) 
{
	if (!root)
		return -1;
	if (root->val == o1 || root->val == o2)
		return root->val;
	int left = lowestCommonAncestor(root->left, o1, o2);
	int right = lowestCommonAncestor(root->right, o1, o2);

	if (left != -1 && right != -1)
		return root->val;
	else if (left != -1)
		return left;
	else if (right != -1)
		return right;
	else
		return -1;
}

void main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	cout << lowestCommonAncestor(root, 5, 1) << endl;
	
}