#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->m_addr = new T[this->m_capacity];
	}

	MyArray(const MyArray<T>& arr)
	{
		this->m_size = arr.m_size;
		this->m_capacity = arr.m_capacity;
		this->m_addr = new T[this->m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->m_addr[i] = arr.m_addr[i];
		}
	}

	~MyArray()
	{
		if (this->m_addr != nullptr)
		{
			delete[] this->m_addr;
			this->m_addr = nullptr;
		}
	}
public:
	MyArray<T> operator=(const MyArray<T>& arr)
	{
		if (this->m_addr != nullptr)
		{
			delete[] this->m_addr;
			this->m_addr = nullptr;
		}
		this->m_size = arr.m_size;
		this->m_capacity = arr.m_capacity;
		this->m_addr = new T[this->m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->m_addr[i] = arr.m_addr[i];
		}
		return *this;
	}

	T& operator[](int index)
	{
		return this->m_addr[index];
	}

	void PushBack(T& data)
	{
		if (this->m_size >= this->m_capacity)
		{
			//����
			cout << "�������������" << endl;
			T* tmp = (T*)realloc(this->m_addr, (this->m_capacity + 3)*sizeof(T));
			if (tmp != nullptr)
			{
				this->m_addr = tmp;
				this->m_capacity += 3;
			}
			//return;
		}
		this->m_addr[this->m_size++] = data;
	}

	void PushBack(T&& data)//C++11 �еķ��������Զ���ʱ�����������ò���
	{
		if (this->m_size >= this->m_capacity)
		{
			//����
			cout << "�������������" << endl;
			T* tmp = (T*)realloc(this->m_addr, (this->m_capacity + 3)*sizeof(T));
			if (tmp != nullptr)
			{
				this->m_addr = tmp;
				this->m_capacity += 3;
			}
			//return;
		}
		this->m_addr[this->m_size++] = data;
	}
public:
	int m_capacity;//����
	int m_size;//��ǰ����Ԫ������
	T* m_addr;// 
};

void test1()
{
	MyArray<int> arr(5);
	for (int i = 0; i < 10; i++)
	{
		arr.PushBack(i);
	}
	arr.PushBack(100);//��ʹ��������������õĺ���void PushBack(T&& data)
	for (int i = 0; i < arr.m_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void main()
{
	test1();
}