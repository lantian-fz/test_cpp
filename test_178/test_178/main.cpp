#define _CRT_SECURE_NO_WARNINGS 1
//牛客-链表中倒数第k个结点
//输入一个链表，输出该链表中倒数第k个结点。

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

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) //双指针
{
	ListNode* p = pListHead;
	ListNode* q = pListHead;
	while (q!=NULL&&k!=0)
	{
		k--;
		q = q->next;
	}
	if (q == NULL&&k > 0)
		return NULL;
	while (q != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}
int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	Insert(head, 6);

	ListNode* q = FindKthToTail(head,7);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(head);

	return 0;
}