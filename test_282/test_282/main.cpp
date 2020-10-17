#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr){}
};

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (!pRoot)
		return pRoot;
	if (k<0)
		return nullptr;
	vector<TreeNode*> ret;
	stack<TreeNode*> st;

	while (!st.empty()||pRoot)
	{
		if (pRoot)
		{
			st.push(pRoot);
			pRoot = pRoot->left;
		}
		else
		{
			pRoot = st.top();
			ret.push_back(pRoot);
			st.pop();
			pRoot = pRoot->right;
		}
	}
	if (k>ret.size())
		return nullptr;
	return ret[k - 1];
}

void main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(7);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	TreeNode* ret = KthNode(root,3);
}