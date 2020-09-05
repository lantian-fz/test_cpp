#define _CRT_SECURE_NO_WARNINGS 1
//¶þ²æÊ÷µÄ²ãÐò±éÀú
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) 
{
	vector<vector<int>> ret;
	if (!root)
		return ret;
	queue<TreeNode*> q;
	q.push(root);
	while (q.size())
	{
		int n = q.size();
		vector<int> arr;
		for (int i = 0; i < n; i++)
		{
			TreeNode* node = q.front();
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			q.pop();
			arr.push_back(node->val);
		}
		ret.push_back(arr);
	}
	return ret;
}

void main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int>>& arr = levelOrder(root);
}

//void main()
//{
//	string s1("123,456,789");
//	string s2("123456", 1, 3);
//	string s3("123456", 3);
//	string s4(4, 'a');
//	string s5(s1, 4);
//	string s6(s3.begin(), s3.end());
//
//
//	cout << "s1: " << s1 << endl;
//	cout << "s2: " << s2 << endl;
//	cout << "s3: " << s3 << endl;
//	cout << "s4: " << s4 << endl;
//	cout << "s5: " << s5 << endl;
//	cout << "s6: " << s6 << endl;
//	cout << s1.find_first_of(",9") << endl;
//}