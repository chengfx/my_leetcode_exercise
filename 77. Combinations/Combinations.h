#pragma once

#include<vector>

class Combinations
{
private:
	void recursive(const std::vector<int>& digitis, std::vector<int>& temp ,std::vector<std::vector<int>>& results, int index, int k);
public:
	void example();
	std::vector<std::vector<int>> combine(int n, int k);
};
