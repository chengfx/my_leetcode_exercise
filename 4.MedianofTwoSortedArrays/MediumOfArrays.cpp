#include "MediumOfArrays.h"
#include <iostream>
using namespace std;

void MediumOfArrays::example()
{
	vector<int> nums1 = { 2 };
	vector<int> nums2 = { };
	cout << "result is :" << findMedianSortedArrays(nums1, nums2) << endl;
}
double MediumOfArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size(), n = nums2.size();
	if ((m == 0) && (n == 0))
		return 0;
	else if (m == 0)
		return static_cast<double>(nums2[n >> 1] + nums2[(n - 1) >> 1]) / 2;
	else if (n == 0)
		return static_cast<double>(nums1[m >> 1] + nums1[(m - 1) >> 1]) / 2;
	int mediumPos = (m + n + 1) >> 1;
	int num1Index = 0, num2Index = 0, lastMoveArray = 1;
	for (int count = 0; (num1Index < m) && (num2Index < n);)
	{
		if (nums1[num1Index] <= nums2[num2Index])
		{
			lastMoveArray = 1;
			num1Index++;
		}
		else
		{
			lastMoveArray = 2;
			num2Index++;
		}
		count++;
		if (count == mediumPos)
		{
			int n1, n2;
			if (lastMoveArray == 1)
				n1 = nums1[num1Index - 1];
			else
				n1 = nums2[num2Index - 1];
			if ((m + n) & 0x1)
				return n1;
			else
			{
				if (num1Index >= m)
					n2 = nums2[num2Index];
				else if (num2Index >= n)
					n2 = nums1[num1Index];
				else {
					n2 = (nums2[num2Index] >= nums1[num1Index]) ? nums1[num1Index] : nums2[num2Index];
				}
				return static_cast<double>(n1 + n2) / 2;
			}
		}
	}
	if (num1Index >= m)
	{
		mediumPos -= m;
		if ((m + n) & 0x1)
			return nums2[mediumPos - 1];
		else
			return static_cast<double>(nums2[mediumPos - 1] + nums2[mediumPos]) / 2;
	}
	if (num2Index >= n)
	{
		mediumPos -= n;
		if ((m + n) & 0x1)
			return nums1[mediumPos - 1];
		else
			return static_cast<double>(nums1[mediumPos - 1] + nums1[mediumPos]) / 2;
	}
	return 0;
}

bool MediumOfArrays::GetKthNumber(vector<int>& nums1, int* nums1Index, vector<int>& nums2, int* nums2Index)
{

}