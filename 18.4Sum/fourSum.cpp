#include"fourSum.h"
#include<algorithm>

using namespace std;

vector<vector<int>> FourSum::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int stop1 = nums.size() - 4, stop2 = nums.size() - 3;
	for (int i = 0; i < stop1; )
	{
		int firstNum = nums[i];
		for (int j = i + 1; j < stop2;)
		{
			int secondNum = nums[j];
			int sum2 = target - firstNum - secondNum;
			int thirdNumIndex = j + 1, fouthNumIndex = nums.size() - 1;
			while (thirdNumIndex < fouthNumIndex)
			{
				int temp = nums[thirdNumIndex] + nums[fouthNumIndex];
				if (temp < sum2)
					++thirdNumIndex;
				else if (temp > sum2)
					--fouthNumIndex;
				else {
					int thirdNum = nums[thirdNumIndex], fouthNum = nums[fouthNumIndex];
					res.push_back(vector<int>{firstNum, secondNum, thirdNum, fouthNum});
					while (thirdNumIndex < fouthNumIndex && nums[thirdNumIndex] == thirdNum) ++thirdNumIndex;
					while (thirdNumIndex < fouthNumIndex && nums[fouthNum] == fouthNum) --fouthNumIndex;
				}
			}
			while (j < stop2 && nums[i] == firstNum) ++i;
		}
		while (i < stop1 && nums[i] == firstNum) ++i;
	}
	return res;
}