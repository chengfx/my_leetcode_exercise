#include"LongestPaSubString.h"
#include<iostream>
using namespace std;

void LongestPaSubString::example()
{
	string s("jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel");
	cout << "result is : " << anotherMethod(s) << endl;
}

string LongestPaSubString::longestPalindrome(string s)
{
	if (s.size() <= 1)
		return string(s);
	int str_size = s.size() - 2;
	int longestLength = 0, longestStartIndex = 0, longestEndIndex = 1;
	int i = 0, preIndex = 0, lastIndex = 0;
	while (i < str_size)
	{
		//look for Palindromic Substring
		int j = i + 1;
		while (j < s.size())
		{
			if (s[i] != s[j])
				break;
			j++;
		}
		if (j == (i + 1) && s[i] == s[i + 2])
			j = i + 3;
		preIndex = i - 1;
		lastIndex = j;
		i = i + 1;
		if (lastIndex - preIndex <= 2)
			continue;
		// make sure the length of the Palindromic Substring
		while ((preIndex >= 0) && (lastIndex < s.size()))
		{
			if (s[preIndex] != s[lastIndex])
				break;
			preIndex--;
			lastIndex++;
		}
		int tempLength = lastIndex - preIndex - 1;
		if (tempLength > longestLength)
		{
			longestLength = tempLength;
			longestStartIndex = preIndex + 1;
			longestEndIndex = lastIndex;
		}
	}
	if ((longestLength < 2) && (s[str_size] == s[str_size + 1]))
	{
		longestStartIndex = str_size;
		longestEndIndex = s.size();
	}
	return string(&s[longestStartIndex], &s[longestEndIndex]);
}

std::string LongestPaSubString::anotherMethod(std::string s)
{
	if (s.size() <= 1)
		return s;
	int longestLength = 1, longestStartIndex = 0;
	for (int i = 0; i < s.size() && (longestLength / 2 < (s.size() - i)); )
	{
		int lastIndex = i + 1;
		while ((lastIndex < s.size()) && (s[lastIndex - 1] == s[lastIndex]))
			lastIndex++;
		int preIndex = i - 1;
		i = lastIndex;
		while ((preIndex>=0) && (lastIndex<s.size()) && (s[preIndex] == s[lastIndex]))
		{
			preIndex--;
			lastIndex++;
		}
		int tempLength = lastIndex - preIndex - 1;
		if (tempLength > longestLength)
		{
			longestLength = tempLength;
			longestStartIndex = preIndex + 1;
		}
	}
	return s.substr(longestStartIndex, longestLength);
}