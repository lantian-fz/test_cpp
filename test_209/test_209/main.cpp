#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�������ľ���
//���������Ķ�����������任ΪԴ�������ľ���

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot)
{
	if (pRoot == nullptr)
		return;
	if (pRoot->left == nullptr&&pRoot->right == nullptr)
		return;
	
	//������������
	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	if (pRoot->left)
		Mirror(pRoot->left);
	if (pRoot->right)
		Mirror(pRoot->right);
}

void main()
{
	TreeNode* a = new TreeNode(3);
	a->left = new TreeNode(4);
	a->right = new TreeNode(5);
	a->left->left = new TreeNode(1);
	a->left->right = new TreeNode(2);

	Mirror(a);
}