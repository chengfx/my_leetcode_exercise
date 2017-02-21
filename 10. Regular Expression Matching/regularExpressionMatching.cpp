#include"regularExpressionMatching.h"
#include<iostream>
using namespace std;

void regularExpressionMatching::example()
{
	regularExpressionMatching test;
	cout << boolalpha <<test.isMatch(string(""), string("")) << endl;
}

bool regularExpressionMatching::isMatch(string s, string p)
{
	int i = 0, j = 0;
	for (;(i < s.size()) && (j < p.size()); ++i, ++j )
	{
		//Judging if s[i] is matching with p[j]
		if (s[i] == p[j] || p[j] == '.') continue;
		//s[i] isn't matching with p[j]
		//Judging if p[j] == '*'and if p[j+1] == '*'  
		if (p[j] != '*')
		{
			int temp = j + 1;
			if (temp >= p.size() || p[temp] != '*') return false;
			++j;
			continue;
		}
		// p[j] == '*'
		if (p[j - 1] == '.') return true;
		if (s[i] != p[j - 1]) return false;
		++i;
		while (i < s.size() && s[i] == p[j - 1])++i;	
	}
	if (p[j] == '*')++j;
	return ((i >= s.size()) && (j >= p.size())) ? true : false;
}