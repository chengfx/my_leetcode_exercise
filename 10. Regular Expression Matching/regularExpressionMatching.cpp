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

	//Starting to check if it's matching
	vector<int> index(1,0);
	for (int i = 0; i < s.size(); i++)
	{
		vector<int> tempIndex;
		for (int j = 0; j < index.size(); j++)
		{
			int temp = index[j];
			if (temp >= p.size())
				continue;
			//check
			if ((s[i] == p[temp]) || (p[temp] == '.'))
				tempIndex.push_back(temp + 1);
			if (p[temp] == '*')
			{
				int preTemp = temp - 1;
				if (p[preTemp] == s[i] || (p[preTemp] == '.'))
					tempIndex.push_back(temp);
				else if (p[preTemp] == '*')
					throw exception(" two '*'");
			}
		}
		index = tempIndex;
	}
	
}