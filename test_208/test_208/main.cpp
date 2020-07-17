#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-树的子结构
//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
//B是A的子结构， 即 A中有出现和B相同的结构和节点值。

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool DoesTree1HaveTree2(TreeNode* a, TreeNode* b)
{
	if (b == nullptr)
		return true;
	if (a == nullptr)
		return false;
	if (a->val != b->val)
		return false;
	return DoesTree1HaveTree2(a->left, b->left) && DoesTree1HaveTree2(a->right, b->right);
}

bool isSubStructure(TreeNode* A, TreeNode* B) 
{
	bool ret = false;

	if (A&&B)
	{
		//第一步判断值是否相同，相同则判断树的结构是否相同
		if (A->val == B->val)
			ret = DoesTree1HaveTree2(A, B);
		//不相同则看A树的子树中，有没有和B树相同的
		if (ret == false)
			ret = isSubStructure(A->left, B);
		if (ret == false)
			ret = isSubStructure(A->right, B);
	}
	return ret;
}

void main()
{
	TreeNode* a = new TreeNode(3);
	a->left = new TreeNode(4);
	a->right = new TreeNode(5);
	a->left->left = new TreeNode(1);
	a->left->right = new TreeNode(2);

	TreeNode* b = new TreeNode(4);
	b->left = new TreeNode(1);

	cout << isSubStructure(a, b) << endl;
}