#define _CRT_SECURE_NO_WARNINGS 1
//��ָoffer-�������к�Ϊĳһֵ��·��
//����һ�Ŷ������ĸ��ڵ��һ�����������ֵ����ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

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

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) 
{

}
void main()
{

}