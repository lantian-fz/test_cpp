#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class myvector
{
public:
	myvector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
	{}

	~myvector()
	{
		dilete[] start;
		start = nullptr;
		finish = nullptr;
		end_of_storage = nullptr;
	}

public:
	size_t size()const
	{
		return finish - start;
	}

	size_t capacity()const
	{
		return end_of_storage - start;
	}

public:
	typedef T* iterator;
	typedef const T* const_iterator;
private:
	iterator start;
	iterator finish;
	iterator end_of_storage;
};


int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);


	return 0;
}