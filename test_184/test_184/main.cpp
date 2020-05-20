#define _CRT_SECURE_NO_WARNINGS 1
//����-142.��������2
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
//��� pos �� - 1�����ڸ�������û�л���˵�����������޸ĸ���������

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
	//���ÿ���ָ�뷨�ж��Ƿ��л������л���������㴦����һ��ָ���ͷ��ʼһ��һ���ߣ�
	//ԭ�����ڵ�ָ��Ҳһ��һ���ߣ������ٴ�����ʱ�Ľ�������ڽ��
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