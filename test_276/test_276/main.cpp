#define _CRT_SECURE_NO_WARNINGS 1
//��������������
//������������������ȣ�
//��������ָ���ĸ���㵽��ԶҶ�ӽ����·���Ͻ���������
//���룺{ 1, 2 }                      �����2
//���룺{ 1, 2, 3, 4, #, #, 5 }       �����3

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr){}
};

int maxDepth_1(TreeNode* root)
{
	// write code here
	if (!root)
		return 0;
	return max(maxDepth_1(root->left), maxDepth_1(root->right)) + 1;
}

int maxDepth_2(TreeNode* root)
{
	if (!root)
		return 0;
	queue<TreeNode*> qe;
	qe.push(root);
	int ret = 0;
	while (qe.size())
	{
		int sz = qe.size();
		for (int i = 0; i < sz; i++)
		{
			TreeNode* tmp = qe.front();
			if (tmp->left)
				qe.push(tmp->left);
			if (tmp->right)
				qe.push(tmp->right);
			qe.pop();
		}
		ret++;
	}
	return ret;
}

void main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	cout << maxDepth_1(root) << endl;
}