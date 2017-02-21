#include"regularExpressionMatching.h"
#include<iostream>
using namespace std;

void regularExpressionMatching::example()
{
	regularExpressionMatching test;
	cout << test.isMatch(string("aa"), string("a")) << endl;
}

bool regularExpressionMatching::isMatch(string s, string p)
{
	//judging if string is empty
	if (s.empty() || p.empty())
		return false;
	int sIndex = 0, sSize = s.size();
	int pIndex = 0, pSize = p.size();
	int matchStartPosIndex = 0;
	for (; matchStartPosIndex < pSize; ++matchStartPosIndex)
	{

	}
	//while (sIndex < sSize)
	//{
	//	char tempChar = s[sIndex];
	//	
	//}
	return true;
}