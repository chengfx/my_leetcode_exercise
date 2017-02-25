#include"regularExpressionMatching.h"
#include<iostream>
#include<vector>
#include<exception>

using namespace std;

void regularExpressionMatching::example()
{
	regularExpressionMatching test;
	cout << boolalpha <<test.isMatch(string(""), string("b*a*c*a*a*")) << endl;

}

bool regularExpressionMatching::isMatch(string s, string p)
{
	//Judging parameters
	if (!p.empty() && (p[0] == '*'))
		throw exception("the first letter of regular expression is *");
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
			int lastTemp = temp + 1;
			if ((s[i] == p[temp]) || (p[temp] == '.'))
				tempIndex.push_back(lastTemp);
			if ((lastTemp < p.size()) && (p[lastTemp] == '*'))
				++temp;
			lastTemp = temp + 1;
			if (p[temp] == '*')
			{
				int preTemp = temp - 1;
				//Judging continous '*'
				if ((p[preTemp] == '*') || ((lastTemp < p.size()) && (p[lastTemp] == '*')))
					throw exception("continous *");
				if (p[preTemp] == s[i] || (p[preTemp] == '.'))
					tempIndex.push_back(temp);
				int k = lastTemp;
				while (k < p.size())
				{
					if ((s[i] == p[k]) || (p[k] == '.'))
						tempIndex.push_back(k + 1);
					++k;
					if ((k < p.size()) && (p[k] == '*'))
						++k;
					else
						break;
				}
			}
		}
		//Matching is fail
		if (tempIndex.empty())
			return false;
		index = tempIndex;
	}
	for (auto& temp : index)
	{
		int lastTemp = temp + 1;
		if (temp >= p.size())
			return true;
		if ((lastTemp == p.size()) && (p[temp] == '*'))
			return true;
		for (int k = lastTemp; k < p.size(); k += 2)
			if ( (p[k] == '*') && (k + 1 == p.size()))
				return true;
	}
	return false;
}