#pragma once

#include <vector>

class TwoSum {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	std::vector<int> twoSumHash(std::vector<int>& nums, int target);
	void example();
};