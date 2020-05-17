#define _CRT_SECURE_NO_WARNINGS 1
//力扣-203.移除链表元素
//删除链表中等于给定值 val 的所有节点。
//输入 : 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5

#include <iostream>
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

ListNode* removeElements(ListNode* head, int val) 
{
	ListNode* p = new ListNode(0);
	p->next = head;
	ListNode* q = p;
	ListNode* t = p->next;
	while (t != NULL)
	{
		if (t->val == val)
		{
			q->next = t->next;
			t = t->next;
			continue;
		}
		q = q->next;
		t = t->next;
	}
	return p->next;
}

int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 6);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	Insert(head, 6);

	ListNode* q = removeElements(head, 6);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(head);
	
	return 0;
}