#define _CRT_SECURE_NO_WARNINGS 1
//牛客-旋转数组的最小数字-剑指offer-8
//链接：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
//来源：牛客网
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3, 4, 5, 1, 2 }为{ 1, 2, 3, 4, 5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include <iostream>
#include <vector>
using namespace std;

//二分法，并没有解决有重复数字的问题
int minNumberInRotateArray_1(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
		return 0;
	int start = 0;
	int end = rotateArray.size() - 1;
	int mid = 0;
	while (rotateArray[start]>=rotateArray[end])
	{
		if (start + 1 == end)
		{
			mid = end;
			break;
		}
		mid = start + (end - start) / 2;
		if (rotateArray[mid] > rotateArray[start])
			start = mid;
		else if (rotateArray[mid] < rotateArray[end])
			end = mid;
	}
	return rotateArray[mid];
}

int minInOrder(vector<int>& arr, int index1, int index2)
{
	int n = arr[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (n > arr[i])
			n = arr[i];
	}
	return n;
}

int minNumberInRotateArray_2(vector<int> &rotateArray)
{
	if (rotateArray.size() == 0)
		return 0;
	int index1 = 0;
	int index2 = rotateArray.size() - 1;
	int mid = index1;
	while (rotateArray[index1] >= rotateArray[index2])
	{
		if (index2 - index1 == 1)
		{
			mid = index2;
			break;
		}
		mid = (index1 + index2) / 2;

		//如果三个数相等，则在该范围内顺序查找
		if (rotateArray[index1] == rotateArray[index2] && rotateArray[mid] == rotateArray[index1])
			return minInOrder(rotateArray, index1, index2);
		if (rotateArray[mid] >= rotateArray[index1])
			index1 = mid;
		else if (rotateArray[mid] <= rotateArray[index2])
			index2 = mid;
	}
	return rotateArray[mid];
}

void main()
{
	//数组{0,1,1,1,1}的两个旋转{1,1,1,0,1}和{1,0,1,1,1}
	vector<int> arr = { 3, 4, 5, 2, 2 };
	cout << minNumberInRotateArray_2(arr) << endl;
}