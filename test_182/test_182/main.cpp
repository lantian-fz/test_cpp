#define _CRT_SECURE_NO_WARNINGS 1
//����-160.�ཻ����
//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//listA = [0,9,1,2,4], listB = [3,2,4]����val=2���ཻ
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

//ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) //����ָ�뷨,ֻ���ж������Ƿ��л�
//{
//	if (headA == nullptr || headB == nullptr)
//		return nullptr;
//	//�Ƚ�һ����������꣬���һ��ָ�����Ϊָ����һ�������ͷ�������Ϳ���ת�����ж������Ƿ���
//	//�������⣬Ȼ���ÿ���ָ�뷨�����ж�
//	ListNode *pa = headA;
//	ListNode *pb = headB;
//	while (pa->next&&pb->next)
//	{
//		pa = pa->next;
//		pb = pb->next;
//	}
//	ListNode *p = nullptr;
//	if (pa->next == nullptr)
//	{
//		pa->next = headA;
//		p = headB;
//	}
//	else
//	{
//		pb->next = headB;
//		p = headA;
//	}
//	ListNode *q = p;
//	int count = 0;
//	while (q&&q->next)
//	{
//		p = p->next;
//		q = q->next->next;
//		if (p == q&&count != 0)
//		{
//			p->next = nullptr;
//			return p;
//		}
//	}
//	return nullptr;
//}

ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) //˫ָ�뷨
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	ListNode *pa = headA;
	ListNode *pb = headB;
	while (pa != pb)
	{
		if (pa)
			pa = pa->next;
		else
			pa = headB;
		if (pb)
			pb = pb->next;
		else
			pb = headA;
	}
	return pa;
}
int main()
{
	ListNode *A = NULL;
	ListNode *B = NULL;
	ListNode *C = NULL;
	Insert(A, 4);
	Insert(A, 1);
	Insert(B, 5);
	Insert(B, 0);
	Insert(B, 1);
	Insert(C, 8);
	Insert(C, 4);
	Insert(C, 5);
	A->next->next = C;
	B->next->next->next = C;

	ListNode* q = getIntersectionNode_2(A,B);

	while (q != NULL)
	{
		cout << q->val << "->";
		q = q->next;
	}
	cout << "NULL" << endl;
	//Clear(A);
	//Clear(B);

	return 0;
}