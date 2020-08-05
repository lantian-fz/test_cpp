#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList_1(ListNode* head) //Ë«Ö¸Õë
{
	ListNode *q = NULL;
	ListNode *p = head;
	while (p != NULL)
	{
		ListNode* t = p->next;
		p->next = q;
		q = p;
		p = t;
	}
	return q;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 2; i <= 5; i++)
	{
		ListNode* s = new ListNode(i);
		p->next = s;
		p = p->next;
	}

	ListNode *q = reverseList_1(head);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	return 0;
}