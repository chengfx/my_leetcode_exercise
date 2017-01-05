#include"TwoSum.h"
#include<iostream>
#include<unordered_map>
using namespace std;

std::vector<int> TwoSum::twoSum(std::vector<int>& nums, int target)
{
	int maxNum = nums[0] , minNum = nums[0];
	//searching maxNum and minNum
	for (size_t i = 0; i<nums.size(); i++)
	{
		if (nums[i] > maxNum)
			maxNum = nums[i];
		if (nums[i] < minNum)
			minNum = nums[i];
	}
	//searching the result
	int diff = maxNum - minNum + 1;
	int offset = -minNum;
	vector<int> tempVec(diff, -1), resultIndex;
	for (size_t i = 0; i<nums.size(); i++)
	{
		int subNum = target - nums[i];
		if (subNum < minNum || subNum > maxNum)
			continue;
		int tempNumIndex = nums[i] + offset;
		int subNumIndex = subNum + offset;
		if (tempVec[subNumIndex] != -1)
		{
			resultIndex.push_back(tempVec[subNumIndex]);
			resultIndex.push_back(i);
			return resultIndex;
		}
		tempVec[tempNumIndex] = i;
	}
	return resultIndex;
}

std::vector<int> TwoSum::twoSumHash(std::vector<int>& nums, int target)
{
	unordered_map<int, int> tempMap;
	vector<int> resultIndex(2,-1);
	cout << "bucket is :" << tempMap.bucket_count() << endl;
	//search the results
	for (size_t i = 0; i<nums.size(); i++)
	{
		int subNum = target - nums[i];
		if (tempMap.find(subNum) != tempMap.end())
		{
			resultIndex[0] = tempMap[subNum];
			resultIndex[1] = i;
			return resultIndex;
		}
		tempMap[nums[i]] = i;
		cout << i << " bucket is :" << tempMap.bucket_count() << endl;
	}
	return resultIndex;
}
void TwoSum::example()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11,30 };
	int target = 50;
	//vector<int> result = twoSum(nums, target);
	vector<int> result = twoSumHash(nums, target);
	cout << "Your answer is : ";
	for (auto& temp : result)
		cout << temp << ',';
	cout << endl;
}