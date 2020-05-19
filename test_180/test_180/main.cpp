#define _CRT_SECURE_NO_WARNINGS 1
//牛客-删除链表中重复的结点
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

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

ListNode* deleteDuplication(ListNode* pHead)//定义两个指针扫描
{
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	ListNode* h = new ListNode(-1);//防止出现前两个结点相同的情况
	h->next = pHead;
	ListNode* t = h;
	ListNode* p = pHead;
	//ListNode* q = pHead->next;
	while (p&&p->next)
	{
		if (p->val == p->next->val)
		{
			while (p->next&&p->val == p->next->val)
				p = p->next;
			t->next = p->next;
			p = p->next;
			continue;
		}
		p = p->next;
		t = t->next;
	}
	return h->next;
}

int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 4);
	Insert(head, 5);

	ListNode* q = deleteDuplication(head);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(head);

	return 0;
}