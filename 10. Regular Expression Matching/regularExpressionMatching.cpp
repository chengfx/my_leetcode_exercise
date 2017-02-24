#include"regularExpressionMatching.h"
#include<iostream>
#include<vector>
#include<exception>

using namespace std;

void regularExpressionMatching::example()
{
	regularExpressionMatching test;
	cout << boolalpha <<test.isMatch(string(""), string("")) << endl;
}

bool regularExpressionMatching::isMatch(string s, string p)
{
	//Judging parameters
	if (!p.empty() && (p[0] == '*'))
		throw exception("the first letter of regular expression is *");
	if (s.empty())
	{
		if (p.empty())
			return true;
		else if ((p.size() > 2) || ((p.size() == 2) && (p[1] != '*')))
			return false;
		else if ((p.size() == 2) && (p[1] == '*'))
			return true;
	}
	if (p.empty())
		return false;

	
}