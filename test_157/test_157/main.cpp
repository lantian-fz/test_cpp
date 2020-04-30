#define _CRT_SECURE_NO_WARNINGS 1
//2020���ŷ�У԰��Ƹc/c++�������A��
//����������
//ʱ�����ƣ�C/C++ 1�룬��������2��
//�ռ����ƣ�C/C++ 32M����������64M
//��ʵ��list_sort��ʹ��ð�ݷ���headָ�������valֵ��С�ų�����
//struct node {
//    int val;
//    struct node *next;
//};
//void list_sort(struct node *head)
//{
//}
//��������:��һ��Ϊ���ݸ��� �ڶ���Ϊ��������ݣ��Կո���зָ�
//�������:���headָ����������ݣ��Կո�ָ�
//��������1:
//12
//10 22 2 5 9 8 1 33 4 6 7 9
//�������1:
//1 2 4 5 6 7 8 9 9 10 22 33

#include <stdio.h>
#include <malloc.h>

struct node 
{
	int val;
	struct node *next;
};

static void list_sort(struct node *head);

struct node *list_create(int arr[], int size)
{
	struct node *head = NULL;
	int i;
	for (i = size - 1; i >= 0; --i) {
		struct node *p = (struct node *)malloc(sizeof(struct node));

		p->val = arr[i];
		p->next = head;
		head = p;
	}
	return head;
}
static void list_print(struct node *head)
{
	for (; head; head = head->next) {
		printf("%d", head->val);
		if (head->next)
			printf(" ");
	}
	printf("\n");
}
static void list_free(struct node *head)
{
	struct node *next;
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}
static int input(int **arr, int *size)
{
	int i;
	int ret;

	ret = fscanf(stdin, "%d\n", size);
	if (ret != 1)
		return -1;
	*arr = (int *)malloc(sizeof(int)* (*size));
	for (i = 0; i < *size; ++i) {
		fscanf(stdin, "%d ", &(*arr)[i]);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	struct node *head;
	int *arr = NULL;
	int size = 0;

	if (input(&arr, &size) < 0) 
	{
		fprintf(stderr, "input error\n");
		return 0;
	}
	head = list_create(arr, size);
	list_sort(head);
	list_print(head);
	list_free(head);
	free(arr);
	return 0;
}

static void list_sort(struct node *head)
{
	//TODO:
}