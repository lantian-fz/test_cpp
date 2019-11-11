#ifndef _MYARRAY_H_
#define _MYARRAY_H_

class MyArray
{
public:
	MyArray();
	MyArray(int len);
	MyArray(const MyArray &another);
	~MyArray();

public:
	void operator=(const MyArray &another);

public:
	void setData(int index, int data);
	int getData(int index);
	int getLen();
	
private:
	int len;
	int	*space;
};

#endif