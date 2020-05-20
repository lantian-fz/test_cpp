#define _CRT_SECURE_NO_WARNINGS 1
//力扣-142.环形链表2
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。说明：不允许修改给定的链表。

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

ListNode *detectCycle(ListNode *head) 
{
	if (head == nullptr)
		return nullptr;
	//先用快慢指针法判断是否有环，若有环，相遇结点处另设一个指针从头开始一步一步走，
	//原来环内的指针也一步一步走，最终再次相遇时的结点就是入口结点
	ListNode *p = head;
	ListNode *q = head;
	do
	{
		if (q == nullptr || q->next == nullptr)
			return nullptr;
		p = p->next;
		q = q->next->next;
	} while (q != p);
	p = head;
	while (q != p)
	{
		q = q->next;
		p = p->next;
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
	head->next->next->next->next = head->next->next;

	ListNode* q = detectCycle(head);

	cout << q->val << endl;
	//while (q != NULL)
	//{
	//	cout << q->val << "->";
	//	q = q->next;
	//}
	//cout << "NULL" << endl;
	//Clear(head);

	return 0;
}