#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


/*
	���⣺����Ԫ�ظ���������1000���������Ϊ10000 �������쳣
	int arr[] = {4,3,1,1,3,3,2};  ɾ��3��Ԫ��
	���ʣ���һ��1������3����������Ϊ2
*/


void printAllElement(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << endl;
}



//���1000���� 0-10000
int OutPutLeftNum(int arr[], int size, int numDelete)
{
	if (numDelete >= size || size <= 0)
	{
		return 0;
	}
	int numValue[10001] = { 0 }; //������ȫ�ַ���ǵ�ÿ�γ�ʼ��
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
				//ʣ���������ִ����ȽϿ����м�����ʣ��
				int nNeed = (((*iter).first) * ((*iter).second) - numDelete) / ((*iter).first);
				if ((((*iter).first) * ((*iter).second) - numDelete) % ((*iter).first) != 0)
				{
					nNeed += 1;
				}
				nSize += nNeed;
				//ע�� numDelete��Ϊ0 ��Ϊ��ɾ������
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
	//��ԭ��������[)������
	sort(arr, arr + size/*, compare*/);

	//printAllElement(arr, size); //1 1 2 3 3 3 4

	//�ֱ�ͳ��ÿ�������ֵĴ��� ����ԭ�����ڴ� 0 -- nNewIndex
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
	//һ���������� ÿ�������ֵĴ����ֱ�Ϊ2 1 3 1
	//printAllElement(arr, nNewIndex + 1); // 2 1 3 1

	//��������С��������
	size = nNewIndex + 1;
	sort(arr, arr + size);
	//printAllElement(arr, size); // 1 1 2 3

	//�������� ��ɾ��k��Ԫ�غ�ʣ�����������
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