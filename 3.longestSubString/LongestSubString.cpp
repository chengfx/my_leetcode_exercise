#include "LongestSubString.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int LongestSubString::lengthOfLongestSubstring(std::string s)
{
	vector<int> hash(128, -1);
	int longestLength = 0;
	int tempLength = 0;
	int startIndex = 0;
	for (size_t i = 0; i<s.size(); i++)
	{
		int index = static_cast<int>(s[i]);
		if ((hash[index] == -1) || (hash[index] < startIndex))
			tempLength += 1;
		else
		{
			if (tempLength > longestLength)
				longestLength = tempLength;
			tempLength = i - hash[index];
			startIndex = hash[index] + 1;
		}
		hash[index] = i;
	}
	if (tempLength > longestLength)
		longestLength = tempLength;
	return longestLength;
}

int LongestSubString::anotherMethod(std::string s)
{
	vector<int> hash(128, -1);
	int longestLength = 0, startIndex = 0;
	int s_size = s.size();
	for (int i = 0; i< s_size; i++)
	{
		int index = static_cast<int>(s[i]);
		if ((hash[index] != -1) && hash[index] > startIndex)
		{
			longestLength = max(longestLength, i - startIndex);
			startIndex = hash[index] + 1;
		}
		hash[index] = i;
	}
	longestLength = max(longestLength, s_size - startIndex);
	return longestLength;
}

void LongestSubString::example()
{
	string s("abcabcbb");
	cout << anotherMethod(s) << endl;
}