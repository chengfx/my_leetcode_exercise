#include"Combinations.h"
#include<iostream>
using namespace std;

void Combinations::example()
{
	vector<vector<int>> results = combine(4, 3);
	for (auto& row : results)
	{
		for (auto& column : row)
			cout << column;
		cout << endl;
	}
}

vector<vector<int>> Combinations::combine(int n, int k)
{
	vector<vector<int>> results;
	vector<int> digits(n, 0),temp;
	for (int i = 0; i < n; i++)
		digits[i] = i + 1;
	results.push_back(digits);
	recursive(digits, temp, results, 0, k);
	return results;
}
void Combinations::recursive(const vector<int>&digits,vector<int>&temp,vector<vector<int>>& results, int index, int k)
{
	if ((digits.size() - index) < k)
		return;
	if (k == 0)
	{
		results.push_back(temp);
		return;
	}
	temp.push_back(digits[index]);
	recursive(digits, temp, results, index + 1, k - 1);
	temp.pop_back();
	recursive(digits, temp, results, index + 1, k);
}