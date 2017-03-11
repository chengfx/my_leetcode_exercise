#include"3Sum.h"
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size();)
	{
		int first = nums[i],front = i + 1, back = nums.size() - 1;
		int temp = -first;
		while (front < back) {
			int frontNumber = nums[front], backNumber = nums[back];
			int sum = frontNumber + backNumber;
			if (sum > temp)
				while (front < back&&nums[back] == backNumber)
					--back;
			else if (sum < temp)
				while (front < back&&nums[front] == frontNumber)
					++front;
			else {
				res.push_back(vector<int>{first, nums[front], nums[back]});
				while (front < back&&nums[front] == frontNumber)
					++front;
			}
		}
		while (i < nums.size() && first == nums[i]) ++i;
	}
	return res;
}