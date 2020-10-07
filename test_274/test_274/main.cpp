#define _CRT_SECURE_NO_WARNINGS 1
//单链表的选择排序
//给定一个无序单链表，实现单链表的选择排序(按升序排序)。
//输入
//[1, 3, 2, 4, 5]
//输出
//{ 1, 2, 3, 4, 5 }

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int _val) :val(_val), next(nullptr){}
};

void Insert(ListNode** head, vector<ListNode*> arr)
{
	if (arr.empty())
		return;
	for (int i = 0; i < arr.size()-1; i++)
		arr[i]->next = arr[i + 1];
	*head = arr[0];
}

ListNode* sortInList(ListNode* head) 
{
	if (!head || !head->next)
		return head;

	ListNode* ret = new ListNode(-1);
	ret->next = head;

	ListNode* sorted = ret;

	while (sorted->next)
	{
		ListNode* pre = sorted;
		ListNode* cur = sorted->next;
		ListNode* preMin = nullptr;
		ListNode* min = nullptr;
		while (cur)
		{
			if (min == nullptr || cur->val < min->val)
			{
				preMin = pre;
				min = cur;
			}
			pre = pre->next;
			cur = cur->next;
		}
		preMin->next = min->next;
		min->next = sorted->next;
		sorted->next = min;
		sorted = min;
	}
	return ret->next;
}

vector<int> StrToArr(string s)
{
	vector<int> ret;
	if (s.empty())
		return ret;
	int i = 0;
	while (i<s.size())
	{
		while (i < s.size() && s[i] == ' ')
			i++;
		string tmp;
		while (i < s.size() && s[i] >= '0'&&s[i] <= '9')
			tmp += s[i++];
		ret.push_back(atoi(tmp.c_str()));
		if (i < s.size())
			i++;
	}
	return ret;
}
void Print(ListNode* head)
{
	if (!head)
		return;
	cout << head->val;
	head = head->next;
	while (head)
	{
		cout << " " << head->val;
		head = head->next;
	}
	cout << endl;
}
void main()
{
	string s;
	while (getline(cin,s))
	{
		ListNode* head = nullptr;

		vector<int> tmp = StrToArr(s);
		vector<ListNode*> arr(tmp.size(), nullptr);

		for (int i = 0; i < tmp.size();i++)
			arr[i] = new ListNode(tmp[i]);

		Insert(&head, arr);

		ListNode* ret = sortInList(head);
		Print(ret);
	}
}