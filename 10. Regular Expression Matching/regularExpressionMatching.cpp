#include"regularExpressionMatching.h"
#include<iostream>
#include<vector>
#include<exception>
#include<unordered_map>

using namespace std;

void regularExpressionMatching::example()
{
	regularExpressionMatching test;
	cout << boolalpha <<test.DP(string("aa"), string("a*")) << endl;

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
		unordered_map<int,int> hashTable;
		for (int j = 0; (j < index.size())&&(index[j]<p.size()); j++)
		{
			int temp = index[j], lastTemp = temp + 1;
			if ((lastTemp < p.size()) && (p[lastTemp] == '*'))
			{
				temp++;
				lastTemp = temp + 1;
			}
			else if ((s[i] == p[temp]) || (p[temp] == '.'))
			{
				if (!hashTable.count(lastTemp))
				{
					hashTable[lastTemp] = 1;
					tempIndex.push_back(lastTemp);
				}
			}	
			if (p[temp] == '*')
			{
				int preTemp = temp - 1;
				//Judging continous '*'
				if ((p[preTemp] == '*') || ((lastTemp < p.size()) && (p[lastTemp] == '*')))
					throw exception("continous *");
				if (p[preTemp] == s[i] || (p[preTemp] == '.'))
				{
					if (!hashTable.count(temp))
					{
						hashTable[temp] = 1;
						tempIndex.push_back(temp);
					}
				}
				int k = lastTemp;
				while (k < p.size())
				{
					if ((s[i] == p[k]) || (p[k] == '.'))
					{
						if (!hashTable.count(k + 1))
						{
							hashTable[k + 1] = 1;
							tempIndex.push_back(k + 1);
						}
					}
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
		if (temp >= p.size()) return true;
		if ((lastTemp == p.size()) && (p[temp] == '*')) return true;
		if (p[temp] == '*') lastTemp++;
		for (int k = lastTemp; k < p.size(); k += 2)
		{
			if (p[k] != '*')break;
			if (k + 1 == p.size())return true;
		}
	}
	return false;
}

bool regularExpressionMatching::DP(string s, string p)
{
	int m = s.size(), n = p.size();
	vector<vector<bool>> table(m + 1, vector<bool>(n + 1, false));
	table[0][0] = true;
	// if s is empty
	for (int i = 2; i <= n; i++)
		table[0][i] = (p[i - 1] == '*') && (table[0][i - 2]);
	for(int i = 1;i<=m;i++)
		for (int j = 1; j <= n; j++)
		{
			int preJ = j - 1, preI = i - 1;
			if (p[preJ] != '*')
				table[i][j] = table[preI][preJ] && ((s[preI] == p[preJ]) || (p[preJ] == '.'));
			else
				table[i][j] = table[i][j - 2] || (table[preI][j] && ((s[preI] == p[j - 2]) || (p[j - 2] == '.')));
		}
	return table[m][n];
}