#define _CRT_SECURE_NO_WARNINGS 1
//����-23.�ϲ�K����������
//�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�
//ʾ�� :
//���� :
//	[
//		1->4->5,
//		1->3->4,
//		2->6
//	]
//��� : 1->1->2->3->4->4->5->6

#include <iostream>
#include <vector>
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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{

}

int main()
{
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	ListNode *head3 = NULL;
	Insert(head1, 1);
	Insert(head1, 4);
	Insert(head1, 5);
	
	Insert(head2, 1);
	Insert(head2, 3);
	Insert(head2, 4);

	Insert(head3, 2);
	Insert(head3, 6);
	vector<ListNode*> arr;
	arr.push_back(head1);
	arr.push_back(head2);
	arr.push_back(head3);
	
	ListNode* p = mergeKLists(arr);
	//Clear(head);

	return 0;
}