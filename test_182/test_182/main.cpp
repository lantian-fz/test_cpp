#define _CRT_SECURE_NO_WARNINGS 1
//力扣-160.相交链表
//编写一个程序，找到两个单链表相交的起始节点。
//listA = [0,9,1,2,4], listB = [3,2,4]，在val=2处相交
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

ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) //快慢指针法
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	//先将一个链表遍历完，最后一个指针更改为指向另一个链表的头，这样就可以转换成判断链表是否有
	//环的问题，然后用快慢指针法进行判断
	ListNode *pa = headA;
	ListNode *pb = headB;
	while (pa->next&&pb->next)
	{
		pa = pa->next;
		pb = pb->next;
	}
	ListNode *p = nullptr;
	if (pa->next == nullptr)
	{
		pa->next = headA;
		p = headB;
	}
	else
	{
		pb->next = headB;
		p = headA;
	}
	ListNode *q = p;
	while (q&&q->next)
	{

		p = p->next;
		q = q->next->next;
		if (p == q)
			return p;
	}
	return nullptr;
}

//ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) //双指针法
//{
//
//}
int main()
{
	ListNode *A = NULL;
	ListNode *B = NULL;
	ListNode *C = NULL;
	Insert(A, 0);
	Insert(A, 9);
	Insert(A, 1);
	Insert(B, 3);
	Insert(C, 2);
	Insert(C, 4);
	A->next->next->next = C;
	B->next = C;

	ListNode* q = getIntersectionNode_1(A,B);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	Clear(A);
	Clear(B);

	return 0;
}