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

int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
		return 0;
	int start = 0;
	int end = rotateArray.size() - 1;
	while ((start + 1) != end)
	{
		int mid = (start + end) / 2;
		if (rotateArray[mid] > rotateArray[start])
			start = mid;
		else if (rotateArray[mid] < rotateArray[end])
			end = mid;
	}
	return rotateArray[end];
}

void main()
{
	vector<int> arr = { 3, 4, 5, 1, 2 };
	cout << minNumberInRotateArray(arr) << endl;
}