#pragma once

#include<vector>

class Combinations
{
private:
	void recursive(std::vector<int>& digitis, std::vector<int>& temp ,std::vector<std::vector<int>>& results, int n, int k);
public:
	void example();
	std::vector<std::vector<int>> combine(int n, int k);
};
