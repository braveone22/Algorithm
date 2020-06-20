#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


/*
	题意：数组元素个数不超过1000个，数最大为10000 不考虑异常
	int arr[] = {4,3,1,1,3,3,2};  删除3个元素
	最后剩余的一个1和三个3，所以种类为2
*/


void printAllElement(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << endl;
}



//最大1000个数 0-10000
int OutPutLeftNum(int arr[], int size, int numDelete)
{
	if (numDelete >= size || size <= 0)
	{
		return 0;
	}
	int numValue[10001] = { 0 }; //不能用全局否则记得每次初始化
	std::map<int, int> mapNum;
	for (int index = 0; index < size; ++index)
	{
		numValue[arr[index]] += 1;
	}
	for (int index = 0; index < 10001; ++index)
	{
		if (numValue[index] != 0)
		{
			std::map<int, int>::iterator iter = mapNum.find(numValue[index]);
			if (iter != mapNum.end())
			{
				(*iter).second += 1;
			}
			else
			{
				mapNum[numValue[index]] = 1;
			}
		}
	}
	int nSize = 0;
	for (std::map<int, int>::iterator iter = mapNum.begin(); iter != mapNum.end(); ++iter)
	{
		if (numDelete > 0)
		{
			if (numDelete > ((*iter).first) * ((*iter).second))
			{
				numDelete -= ((*iter).first) * ((*iter).second);
			}
			else
			{
				//剩余个数与出现次数比较看还有几类数剩余
				int nNeed = (((*iter).first) * ((*iter).second) - numDelete) / ((*iter).first);
				if ((((*iter).first) * ((*iter).second) - numDelete) % ((*iter).first) != 0)
				{
					nNeed += 1;
				}
				nSize += nNeed;
				//注意 numDelete置为0 因为都删除完了
				numDelete = 0;
			}
		}
		else
		{
			nSize += (*iter).second;
		}
	}
	return nSize;
}

bool compare(int a, int b)
{
	return a>b;
}
int OutPutLeftNumTwo(int arr[], int size, int numDelete)
{
	if (size <= 0 || numDelete >= size)
	{
		return 0;
	}
	//对原数组排序[)内排序
	sort(arr, arr + size/*, compare*/);

	//printAllElement(arr, size); //1 1 2 3 3 3 4

	//分别统计每个数出现的次数 复用原数组内存 0 -- nNewIndex
	int nTemp = arr[0];
	int nNewIndex = 0;
	arr[nNewIndex] = 1;
	for (int i = 1; i < size; i++)
	{
		if (nTemp == arr[i])
		{
			arr[nNewIndex] += 1;
		}
		else
		{
			nTemp = arr[i];
			arr[++nNewIndex] = 1;
		}
	}
	//一共有四种数 每个数出现的次数分别为2 1 3 1
	//printAllElement(arr, nNewIndex + 1); // 2 1 3 1

	//按次数从小到大排序
	size = nNewIndex + 1;
	sort(arr, arr + size);
	//printAllElement(arr, size); // 1 1 2 3

	//遍历数组 求删除k个元素后剩余的数的种类
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		if (sum > numDelete)
		{
			return size - i;
		}
		else if (sum == numDelete)
		{
			return (size - (i + 1));
		}
	}
	return 0;
}


int main()
{
	int arr[] = { 4,3,1,1,3,3,2 };
	/*int arr[] = {5,4,4};*/
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 1) << endl;
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 2) << endl;
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 3) << endl;
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 4) << endl;
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 5) << endl;
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 6) << endl;
	std::cout << OutPutLeftNum(arr, sizeof(arr) / sizeof(int), 7) << endl;

	cout << "----------------------------------------------------" << endl;

	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 1) << endl;
	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 2) << endl;
	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 3) << endl;
	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 4) << endl;
	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 5) << endl;
	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 6) << endl;
	std::cout << OutPutLeftNumTwo(arr, sizeof(arr)/sizeof(int) , 7) << endl;
	getchar();
	return 0;
}