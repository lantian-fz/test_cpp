#define _CRT_SECURE_NO_WARNINGS 1
//ɾ������ĵ�����n���ڵ�
//����һ������ɾ������ĵ�����n���ڵ㲢���������ͷָ��
//���磬
// ����������Ϊ:1->2->3->4->5, n= 2.
// ɾ��������ĵ�����n���ڵ�֮��,�����Ϊ1->2->3->5.
//��ע����Ŀ��֤nһ������Ч��,����������ʱ�临�Ӷ�ΪO(n)���㷨
//
//����:{1,2},2       ���:{2}

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int _val) :val(_val), next(nullptr){}
};

void Insert(ListNode** head, vector<ListNode*> arr)
{
	if (arr.empty())
		return;
	for (int i = 0; i < arr.size() - 1; i++)
		arr[i]->next = arr[i + 1];
	*head = arr[0];
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	// write code here
	ListNode* ret = new ListNode(-1);
	ret->next = head;
	ListNode* p1 = head;
	ListNode* p2 = head;
	while (p2&&n)//n���ں���Χ�ڵ�
	{
		p2 = p2->next;
		n--;
	}
	if (!p2&&!n)
		ret->next = head->next;
	else
	{
		while (p2->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		p1->next = p1->next->next;
	}
	return ret->next;
}

void main()
{
	int n = 0;
	cin >> n;
	vector<ListNode*> arr(n, nullptr);
	int tmp = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		cin >> tmp;
		arr[i] = new ListNode(tmp);
	}
	ListNode* head = nullptr;
	Insert(&head, arr);
	int x = 0;
	cin >> x;
	ListNode* ret = removeNthFromEnd(head, x);
	ListNode* p = ret;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

//char* fun(char pre_str[10])
//{
//	for (int i = 0; i < strlen(pre_str); i++)
//	{
//		if (pre_str[i] == 'b')
//		{
//			char trans_str[10] = { 0 };
//			trans_str[0] = pre_str[i];
//			pre_str[i] = pre_str[strlen(pre_str) - i - 1];
//			pre_str[strlen(pre_str) - i - 1] = trans_str[0];
//		}
//		else if (pre_str[i] == 'c')
//			strcat(pre_str, "b");
//	}
//	return pre_str;
//}
//
//void main()
//{
//	char str[] = "bacdefgh";
//	char* ret = fun(str);
//	cout << ret << endl;
//}