#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�����ӽṹ
//�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)
//B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��

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
		//��һ���ж�ֵ�Ƿ���ͬ����ͬ���ж����Ľṹ�Ƿ���ͬ
		if (A->val == B->val)
			ret = DoesTree1HaveTree2(A, B);
		//����ͬ��A���������У���û�к�B����ͬ��
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