#include"regularExpressionMatching.h"
#include<iostream>
#include<vector>

using namespace std;

void regularExpressionMatching::example()
{
	regularExpressionMatching test;
	cout << boolalpha <<test.isMatch(string(""), string("")) << endl;
}

bool regularExpressionMatching::isMatch(string s, string p)
{
	//Judging parameters
	if (s.empty())
	{
		if (p.empty())
			return true;
		else if ((p.size() > 2) || ((p.size() == 2) && (p[1] != '*')))
			return false;
	}
	if (p.empty())
		return false;

	
}