#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
class BSTree;

template<typename T>
class BSTNode
{
	friend class BSTree<T>;
public:
	BSTNode(T d = T(),BSTNode<T> *left=nullptr,BSTNode<T> *right=nullptr)
		:data(d), leftChild(left), rightChild(right)
	{
	}
	~BSTNode()
	{
	}
private:
	T data;
	BSTNode<T> *leftChild;
	BSTNode<T> *rightChild;
};

template<typename T>
class BSTree
{
public:
	BSTree() :root(nullptr)
	{}
	BSTree(T arr[], int n) :root(nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			Insert(arr[i]);
		}
	}
public:
	bool Insert(const T &x);
	T Max()const;
	T Min()const;
	void Order()const;//ÖÐÐò±éÀú
	BSTNode<T>* Find(const T &key);
protected:
	bool Insert(BSTNode<T>* &t, const T &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<T>(x);
			return true;
		}
		else if (x < t->data)
		{
			return Insert(t->leftChild, x);
		}
		else if (x>t->data)
		{
			return Insert(t->rightChild, x);
		}
	}

	T Max(BSTNode<T> *t)const
	{
		assert(t);
		while (t->rightChild != nullptr)
			t = t->rightChild;
		return t->data;
	}

	T Min(BSTNode<T> *t)const
	{
		assert(t);
		while (t->leftChild != nullptr)
			t = t->leftChild;
		return t->data;
	}

	void Order(BSTNode<T> *t)const
	{
		if (t != nullptr)
		{
			Order(t->leftChild);
			cout << t->data << " ";
			Order(t->rightChild);
		}
	}

	BSTNode<T>* Find(BSTNode<T> *t, const T &key)
	{
		if (t == nullptr || key == t->data)
			return t;
		if (key < t->data)
			return Find(t->leftChild, key);
		else 
			return Find(t->rightChild, key);
	}

private:
	BSTNode<T> *root;
};

template<typename T>
T BSTree<T>::Max()const
{
	return Max(root);
}

template<typename T>
T BSTree<T>::Min()const
{
	return Min(root);
}

template<typename T>
bool BSTree<T>::Insert(const T &x)
{
	return Insert(root, x);
}

template<typename T>
void BSTree<T>::Order()const
{
	Order(root); 
	cout << endl;
}
template<typename T>
BSTNode<T>* BSTree<T>::Find(const T &key)
{
	return Find(root, key);
}

void main()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BSTree<int> bst(arr,n); 

	//for (int i = 0; i < n; i++)
	//{
	//	bst.Insert(arr[i]);
	//}
	bst.Order();
	cout << bst.Max() << endl;
	cout << bst.Min() << endl;
	cout << "----------------" << endl;
	BSTNode<int>* p = bst.Find(8);

}