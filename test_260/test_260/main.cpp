#define _CRT_SECURE_NO_WARNINGS 1
//¶þ²æÊ÷µÄ¾µÏñ-·ÇµÝ¹é

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

void Mirror(TreeNode *pRoot) 
{
	if (!pRoot)
		return;
	queue<TreeNode*> qe;
	qe.push(pRoot);
	while (qe.size())
	{
		TreeNode* t = qe.front();
		TreeNode* tmp = t->left;
		t->left = t->right;
		t->right = tmp;
		if (t->left)
			qe.push(t->left);
		if (t->right)
			qe.push(t->right);
		qe.pop();
	}
}

void main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(7);
	root->right = new TreeNode(10);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);

	Mirror(root);
}