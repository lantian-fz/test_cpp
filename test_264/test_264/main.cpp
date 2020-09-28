#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int _val) :val(_val), next(nullptr){}
};

void InitList(ListNode** head,vector<ListNode*> arr)
{
	if (!arr.size())
		return;
	for (int i = 0; i < arr.size()-1; i++)
		arr[i]->next = arr[i + 1];
	*head = arr[0];
}

ListNode* DoubleList(ListNode* head1, ListNode* head2)
{
	if (!head1)
		return head2;
	if (!head2)
		return head2;
	ListNode* ret = new ListNode(-1);
	ListNode* retp = ret;
	ListNode* p1 = head1;
	ListNode* p2 = head2;
	while (p1&&p2)
	{
		if (p1->val < p2->val)
		{
			retp->next = p1;
			p1 = p1->next;
		}
		else
		{
			retp->next = p2;
			p2 = p2->next;
		}
		retp = retp->next;
	}
	while (p1)
	{
		retp->next = p1;
		retp = retp->next;
		p1 = p1->next;
	}
	while (p2)
	{
		retp->next = p2;
		retp = retp->next;
		p2 = p2->next;
	}
	return ret->next;
}

int main()
{
	int m = 0, n = 0, tmp = 0;
	while (cin >> m)
	{
		ListNode* head1 = nullptr;
		vector<ListNode*> arr1(m,nullptr);
		for (int i = 0; i < m; i++)
		{
			cin >> tmp;
			arr1[i] = new ListNode(tmp);
		}
		InitList(&head1, arr1);

		ListNode* head2 = nullptr;
		cin >> n;
		vector<ListNode*> arr2(n, nullptr);
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			arr2[i] = new ListNode(tmp);
		}
		InitList(&head2, arr2);


		ListNode* ret = DoubleList(head1, head2);
		ListNode* p = ret;
		if (p)
		{
			cout << p->val;
			p = p->next;
			while (p)
			{
				cout << " " << p->val;
				p = p->next;
			}
			cout << endl;
		}
	}

	return 0;
}