#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 8

typedef int Datatype;

typedef struct CircleQueue
{
	Datatype *data;
	int front;
	int rear;
}CircleQueue;

void QueueInit(CircleQueue *q)//��ʼ��
{
	q->data = (Datatype*)malloc(sizeof(Datatype)*MAXSIZE);
	assert(q->data);
	q->front = 0;
	q->rear = 0;
}

int QueueEmpty(CircleQueue *q)//�жӿ�
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int QueueEnter(CircleQueue *q, Datatype x)//���
{
	if ((q->rear + 1) % MAXSIZE == q->front)//�ж϶���
		return 0;
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

int QueueDelete(CircleQueue *q, Datatype *x)//����
{
	if (QueueEmpty(q))//�жӿ�
		return 0;
	*x = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return 1;
}

void QueueShow(CircleQueue *q)//��ʾ
{
	int n = (q->rear - q->front + MAXSIZE) % MAXSIZE;
	int i = q->front;
	printf("Ԫ�أ�");
	while (n--)
	{
		printf("%d ", q->data[i]);
		i = (i + 1) % MAXSIZE;
	}
	n = (q->rear - q->front + MAXSIZE) % MAXSIZE;
	i = q->front;
	printf("\nλ�ã�");
	while (n--)
	{
		printf("%d ", i);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}

void Menu()
{
	printf("          ѡ��\n");
	printf("*    1.���    2.����     *\n");
	printf("*    3.��ʾ    0.�˳�     *\n");
}

int main()
{
	int input = 0;
	int x = 0;
	CircleQueue qu;
	QueueInit(&qu);//��ʼ��ѭ������

	do
	{
		Menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ԫ��(��-1����):");
			while (scanf("%d", &x), x != -1)
			{
				if (QueueEnter(&qu, x) == 0)
					printf("����������%d ���ʧ��\n", x);
			}
			break;
		case 2:
			if (QueueDelete(&qu, &x))
				printf("%d����\n", x);
			else
				printf("����Ϊ�գ�����ʧ��\n");
			break;
		case 3:
			QueueShow(&qu);
			break;
		case 0:
			break;
		default:
			printf("û�����ѡ��!\n");
		}
	} while (input);

	printf("\n");
	system("pause");
	return 0;
}
/*
//���������� 
#include<stdio.h>  
#include<stdlib.h>  

typedef struct BiTNode
{
	int key;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree &p)//���� 
{
	if (!T)  
	{
		p = f; 
		return 0; 
	}
	else if (key == T->key) 
	{ 
		p = T; 
		return 1; 
	}
	else if (key<T->key) 
		SearchBST(T->lchild, key, T, p);
	else 
		SearchBST(T->rchild, key, T, p);
}

int InsertBST(BiTree &T, int key)//���� 
{
	if (!T)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->key = key;
		T->lchild = (T)->rchild = NULL;
		return 1;
	}
	if (key == T->key) 
		return 0;
	if (key>T->key) 
		InsertBST(T->rchild, key);
	else 
		InsertBST(T->lchild, key);
}

void InorderTraverse(BiTree T)//�������
{
	if (T)
	{
		InorderTraverse(T->lchild);
		printf("%d ", T->key);
		InorderTraverse(T->rchild);
	}
}

void Delete(BiTree &p) //ɾ�� 
{
	BiTree q, s;
	if (!p->lchild &&!p->rchild) //pΪҶ�ӽڵ�  
		p = NULL;
	else if (!p->lchild) //������Ϊ�գ��ؽ�������
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild) //������Ϊ�գ��ؽ�������
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else  //������������Ϊ��   
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		p->key = s->key;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
}

int DeleteBST(BiTree &T, int key)//ɾ�� 
{
	if (!T) 
		return 0;
	else
	{
		if (key == T->key) Delete(T);
		else if (key<T->key)  
			DeleteBST(T->lchild, key);
		else 
			DeleteBST(T->rchild, key);
	}
}

int main()
{
	int e = 0, n = 0;
	BiTree T = NULL, f=NULL, p=NULL;
	printf("���볤�ȣ�");
	scanf("%d", &n);
	printf("����Ԫ�أ�");
	while (n--)
	{
		scanf("%d", &e);
		InsertBST(T, e);
	}
	printf("���������");
	InorderTraverse(T);
	printf("\n");
	while (1)
	{
		printf("����Ҫ����Ԫ�أ�");
		scanf("%d", &e);
		if (SearchBST(T, e, f, p)) 
			printf("�ҵ���\n");
		else 
			printf("û�ҵ�\n");
		printf("����Ҫ����Ԫ�أ�");
		scanf("%d", &e);
		InsertBST(T, e);
		printf("���������");
		InorderTraverse(T);
		printf("\n");
		printf("����Ҫɾ��Ԫ�أ�");
		scanf("%d", &e);
		DeleteBST(T, e);
		printf("���������");
		InorderTraverse(T);
		printf("\n");
	}
}
*/