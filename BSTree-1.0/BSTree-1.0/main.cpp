#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
using namespace std;

template<typename Type>
class BSTree;

template<typename Type>
class BSTNode
{
	friend class BSTree<Type>;
public:
	BSTNode(Type d = Type(), BSTNode<Type> *left = nullptr, BSTNode<Type> *right = nullptr)
		:data(d), leftChild(left), rightChild(right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type>* leftChild;
	BSTNode<Type>* rightChild;
};

template<typename Type>
class BSTree
{
public:
	BSTree() :root(nullptr)
	{}
	~BSTree()
	{
		Clear();
	}
public:
	bool Insert(const Type &x);
	Type Max()const;
	Type Min()const;
	void Order()const;
	BSTNode<Type>* Find(const Type &key);
	void Clear();
	bool Remove(const Type &key);
protected:
	bool Insert(BSTNode<Type> *&t, const Type &x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if (x < t->data)
			return Insert(t->leftChild, x);
		else
			return Insert(t->rightChild, x);
		return false;
	}
	Type Max(BSTNode<Type> *t)const
	{
		assert(t);
		while (t->rightChild != nullptr)
			t = t->rightChild;
		return t->data;
	}
	Type Min(BSTNode<Type> *t)const
	{
		assert(t);
		while (t->leftChild != nullptr)
			t = t->leftChild;
		return t->data;
	}
	void Order(BSTNode<Type> *t)const
	{
		if (t != nullptr)
		{
			Order(t->leftChild);
			cout << t->data << " ";
			Order(t->rightChild);
		}
	}
	BSTNode<Type>* Find(BSTNode<Type> *t, const Type &key)
	{
		if (t != nullptr)
		{
			if (key < t->data)
				Find(t->leftChild, key);
			else if (key>t->data)
				Find(t->rightChild, key);
			else
				return t;
		}
		else
			return t;
	}
	void Clear(BSTNode<Type> *&t)
	{
		if (t !=nullptr)
		{
			Clear(t->leftChild);
			Clear(t->rightChild);
			delete t;
			t = nullptr;
		}
	}
	bool Remove(BSTNode<Type> *&t, const Type &key)//ตÝน้
	{
		if (t == nullptr)
			return false;
		if (key < t->data)
			return Remove(t->leftChild, key);
		else if (key>t->data)
			return Remove(t->rightChild, key);
		else
		{
			if (t->leftChild == nullptr&&t->rightChild == nullptr)
			{
				delete t;
				t = nullptr;
			}
			else if (t->leftChild == nullptr&&t->rightChild != nullptr)
			{
				BSTNode<Type>* p = t;
				t = p->rightChild;
				delete p;
				p = nullptr;
			}
			else if (t->leftChild != nullptr&&t->rightChild == nullptr)
			{
				BSTNode<Type>* p = t;
				t = p->leftChild;
				delete p;
				p = nullptr;
			}
			else if (t->leftChild != nullptr&&t->rightChild != nullptr)
			{
				BSTNode<Type>* p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;
				t->data = p->data;
				Remove(t->leftChild, t->data);
			}
			return true;
		}
	}
private:
	BSTNode<Type>* root;
};

template<typename Type>
bool BSTree<Type>::Insert(const Type &x){return Insert(root, x);}

template<typename Type>
Type BSTree<Type>::Max()const{return Max(root);}

template<typename Type>
Type BSTree<Type>::Min()const{ return Min(root); }

template<typename Type>
void BSTree<Type>::Order()const{ Order(root); }

template<typename Type>
BSTNode<Type>* BSTree<Type>::Find(const Type &key){ return Find(root,key); }

template<typename Type>
void BSTree<Type>::Clear(){ Clear(root); }

template<typename Type>
bool BSTree<Type>::Remove(const Type &key){ return Remove(root, key); }

int main()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BSTree<int> bst;

	for (int i = 0; i < sz; i++)
	{
		bst.Insert(arr[i]);
	}
	bst.Remove(8); 

	//cout << bst.Max() << endl;
	//cout << bst.Min() << endl;
	bst.Order();
	cout << endl;
	//BSTNode<int> *b = bst.Find(2);
	return 0;
}