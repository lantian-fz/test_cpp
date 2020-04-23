#define _CRT_SECURE_NO_WARNINGS 1
//数组中出现次数超过一半的数字
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//数组排序后，如果符合条件的数存在，则一定是数组中间那个数
int MoreThanHalfNum_Solution_1(vector<int> numbers) 
{
	size_t ret = 0;
	sort(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[numbers.size() / 2])
			ret++;
		if (ret>numbers.size() / 2)
			return numbers[numbers.size() / 2];
	}
	return 0;
}

int MoreThanHalfNum_Solution_2(vector<int> numbers)
{
	size_t ret = 1;
	if (numbers.size() == 1)
		return numbers[0];
	sort(numbers.begin(), numbers.end());
	for (size_t i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[i - 1])
		{
			ret++;
			if (ret>numbers.size() / 2)
				return numbers[i];
		}
		else
			ret = 1;
	}
	return 0;
}

//时间复杂度最小为O(n)
//思路：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。在遍历数组时保存两个值：
//一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
//若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
int MoreThanHalfNum_Solution_3(vector<int> numbers)
{
	int n = numbers[0];
	int count = 1;
	for (size_t i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == n)
			count++;
		else
			count--;
		if (count == 0)
		{
			n = numbers[i];
			count = 1;
		}
	}
	count = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == n)
			count++;
	}
	
	return count * 2 > numbers.size() ? n : 0;//numbers.size()/2会有偏差
}
//不行，反例[1,2,2,3,3,4,4,5,5]
//int MoreThanHalfNum_Solution_4(vector<int> numbers)
//{
//	int ret = 0;
//	set<int> st(numbers.begin(), numbers.end());
//	sort(numbers.begin(), numbers.end());
//	if ((st.size() - 1) * 2 < numbers.size())//去掉其中长度可能超过一半的那个数
//		return numbers[numbers.size() / 2];
//	else
//		return 0;
//}

int main()
{
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution_1(arr) << endl;
	cout << MoreThanHalfNum_Solution_2(arr) << endl;
	cout << MoreThanHalfNum_Solution_3(arr) << endl;

	return 0;
}