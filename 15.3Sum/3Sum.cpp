#include"3Sum.h"
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	unordered_map<int, int> isExist(3 * nums.size());
	if (nums.size() <= 2)
		return res;
	int* hash2sums = new int[nums.size()];
	for (int i = 0; i < nums.size(); i++)
		hash2sums[i] = 0 - nums[i];
	for (int i = 0; i < nums.size(); ++i)
	{
		unordered_map<int, int> hashTable(3 * nums.size());
		for (int j = i+1; j < nums.size(); ++j)
		{
			if (isExist.find[j] != isExist.end()) continue;
			hashTable[nums[j]] = j;
			int otherTemp = hash2sums[i] - nums[j];
			if (hashTable.find(otherTemp) != hashTable.end())
				if(hashTable[otherTemp]>i && hashTable[otherTemp]<j)
					res.push_back(vector<int>{nums[i], nums[j], otherTemp});
		}
		isExist[nums[i]] = 1;
	}
	delete[]hash2sums;
	return res;
}