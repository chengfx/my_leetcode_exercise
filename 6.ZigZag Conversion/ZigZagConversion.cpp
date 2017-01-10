#include "ZigZagConversion.h"
#include<iostream>
using namespace std;

void ZigZagConversion::example()
{
	string s("AB");
	string result = convert(s, 1);
	cout << "result is: "<< result << endl;
}

string ZigZagConversion::convert(std::string s, int numRows)
{
	int strLength = s.size();
	if (strLength <= numRows || (numRows == 1))
		return s;
	int nums = (numRows << 1) - 2;
	string result;
	for (int i = 0; i < numRows; i++)
	{
		int j = 0, pos = j + i;
		while (pos < strLength)
		{
			result.push_back(s[pos]);
			j += nums;
			if ((i == 0) || (i == numRows - 1))
				pos = j + i;
			else
			{
				pos = j - i;
				if (pos >= strLength)
					break;
				result.push_back(s[pos]);
				pos = j + i;
			}
		}
	}
	return result;
}