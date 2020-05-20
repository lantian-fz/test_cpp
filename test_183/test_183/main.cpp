#define _CRT_SECURE_NO_WARNINGS 1
//力扣-141.环形链表
//给定一个链表，判断链表中是否有环。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
//如果 pos 是 -1，则在该链表中没有环。
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1      输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//示例 2：
//输入：head = [1, 2], pos = 0             输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//示例 3：
//输入：head = [1], pos = -1               输出：false
//解释：链表中没有环。

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

bool hasCycle_1(ListNode *head) //快慢指针法
{
	if (head == nullptr)
		return false;
	ListNode *p = head;
	ListNode *q = head;
	do
	{
		if (q==nullptr||q->next==nullptr)
			return false;
		p = p->next;
		q = q->next->next;
	}while (p != q);
	return true;
}

int main()
{
	ListNode *head = NULL;
	Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	head->next->next->next->next = head->next->next;

	cout << hasCycle_1(head) << endl;
	//Clear(head);

	return 0;
}