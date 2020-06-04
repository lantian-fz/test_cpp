#define _CRT_SECURE_NO_WARNINGS 1
//力扣-23.合并K个排序链表
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//示例 :
//输入 :
//	[
//		1->4->5,
//		1->3->4,
//		2->6
//	]
//输出 : 1->1->2->3->4->4->5->6

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void Insert(ListNode *&head, const int x)
{
	if (head == NULL)
		head = new ListNode(x);
	else
		Insert(head->next, x);
}

void Clear(ListNode *&head)
{
	while (head != NULL)
	{
		ListNode* r = head;
		head = r->next;
		delete r;
		r = NULL;
	}
}

ListNode* mergeKLists(vector<ListNode*>& lists) //暴力法，用数组存储元素，排序后构造新链表
{
	int n = lists.size();
	if (n == 0)
		return nullptr;
	if (n == 1)
		return lists[0];
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		ListNode *p = lists[i];
		if (p == nullptr)
			continue;
		while (p)
		{
			arr.push_back(p->val);
			p = p->next;
		}
	}
	if (arr.size() == 0)
		return nullptr;
	sort(arr.begin(), arr.end());
	ListNode *new_lists = new ListNode(arr[0]);
	ListNode *q = new_lists;
	for (int i = 1; i < arr.size(); i++)
	{
		q->next = new ListNode(arr[i]);
		q = q->next;
	}
	return new_lists;
}

int main()
{
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	ListNode *head3 = NULL;
	Insert(head1, 1);
	Insert(head1, 4);
	Insert(head1, 5);
	
	Insert(head2, 1);
	Insert(head2, 3);
	Insert(head2, 4);

	Insert(head3, 2);
	Insert(head3, 6);
	vector<ListNode*> arr;
	arr.push_back(head1);
	arr.push_back(head2);
	arr.push_back(head3);
	
	ListNode* p = mergeKLists(arr);
	Clear(head1);
	Clear(head2);
	Clear(head3);
	Clear(p);

	return 0;
}