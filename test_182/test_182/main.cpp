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

ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) //����ָ�뷨
{
	if (headA == nullptr || headB == nullptr)
		return nullptr;
	//�Ƚ�һ����������꣬���һ��ָ�����Ϊָ����һ�������ͷ�������Ϳ���ת�����ж������Ƿ���
	//�������⣬Ȼ���ÿ���ָ�뷨�����ж�
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

//ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) //˫ָ�뷨
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