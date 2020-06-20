#include<iostream>

using namespace  std;

int g_num = 100;


bool bInvalid(string strValue)
{
	if (strValue.empty())
	{
		return true;
	}
	int nLeftNum = 0;
	int nLength = strValue.length();
	for (int i = 0; i < nLength; i++)
	{
		if ('(' == strValue.at(i))
		{
			nLeftNum += 1;
		}
		else if (')' == strValue.at(i))
		{
			nLeftNum -= 1;
			if (nLeftNum < 0)
			{
				return false;
			}
		}
	}

	return (0 == nLeftNum);
}

int main()
{
	std::cout << bInvalid("(((123(0)()3)3))");

	getchar();

	return 0;
}