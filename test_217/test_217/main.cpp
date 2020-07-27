#define _CRT_SECURE_NO_WARNINGS 1
//剑指offer-二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

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

void ConvertNode(TreeNode* pNode, TreeNode*& pInList)
{
	if (pNode == nullptr)
		return;
	TreeNode* current = pNode;

	if (current->left != nullptr)
		ConvertNode(current->left, pInList);

	current->left = pInList;
	if (pInList != nullptr)
		pInList->right = current;

	pInList = current;
	if (current->right != nullptr)
		ConvertNode(current->right, pInList);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* pInList = nullptr;//用来指向双向链表的尾结点
	ConvertNode(pRootOfTree, pInList);

	TreeNode* head = pInList;
	while (head != nullptr && head->left != nullptr)
		head = head->left;
	return head;
}

////////////////////////////////////////////////////////////
void print(TreeNode* root, vector<TreeNode*>& arr)
{
	if (root == nullptr)
		return;
	print(root->left, arr);
	arr.push_back(root);
	print(root->right, arr);
}

TreeNode* Convert_2(TreeNode* pRootOfTree)
{
	TreeNode* p = pRootOfTree;
	vector<TreeNode*> arr;
	if (!p)
		return nullptr;
	print(pRootOfTree, arr);
	if (arr.size() == 1)
		return arr[0];
	arr[0]->left = nullptr;
	arr[0]->right = arr[1];

	int i = 0;
	for (i = 1; i < arr.size()-1; i++)
	{
		arr[i]->left = arr[i - 1];
		arr[i]->right = arr[i + 1];
	}
	arr[i]->left = arr[i - 1];
	arr[i]->right = nullptr;
	return arr[0];
}
void main()
{
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(6);
	root->right = new TreeNode(14);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(8);
	root->right->left = new TreeNode(12);
	root->right->right = new TreeNode(16);
	
	TreeNode* head = Convert_2(root);

	TreeNode* p = head;
	while (p)
	{
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;
}