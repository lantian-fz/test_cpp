#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�������´�ӡ������
//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
}; 
vector<int> PrintFromTopToBottom(TreeNode* root)
{
	vector<int> arr;
	queue<TreeNode*> q;
	if (!root)
		return arr;
	q.push(root);
	while (q.size())
	{
		TreeNode* p = q.front();
		q.pop();
		arr.push_back(p->val);
		if (p->left)
			q.push(p->left);
		if (p->right)
			q.push(p->right);
	}
	return arr;
}

void main()
{
	TreeNode* a = new TreeNode(3);
	a->left = new TreeNode(4);
	a->right = new TreeNode(5);
	a->left->left = new TreeNode(1);
	a->left->right = new TreeNode(2);

	vector<int>& arr = PrintFromTopToBottom(a);
	for (auto e : arr)
		cout << e << " ";
}