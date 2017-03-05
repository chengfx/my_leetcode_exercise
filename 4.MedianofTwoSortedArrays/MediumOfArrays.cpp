#include "MediumOfArrays.h"
#include <iostream>
using namespace std;

void MediumOfArrays::example()
{
	vector<int> nums1 = {1,3,5,6,9,11 };
	vector<int> nums2 = {2,4,7,8,10,12 };
	int a = 0, b = 0;
	cout << "result is :" << findMedianSortedArrays(nums1, nums2) << endl;
	GetKthNumber(nums1, &a, nums2, &b, 11);
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

bool MediumOfArrays::GetKthNumber(vector<int>& nums1, int* nums1Index, vector<int>& nums2, int* nums2Index,int kth)
{
	int nums1Length = nums1.size(), nums2Length = nums2.size();
	//critical condition
	if (kth > (nums1Length + nums2Length)) return false;
	*nums1Index = ((kth > nums1Length) ? nums1Length : kth) - 1;
	*nums2Index = kth - (*nums1Index) - 2;
	int posStart = (kth - nums2Length) > 0 ? kth - nums2Length : 0, posEnd = *nums1Index, posMid = (posStart + posEnd) >> 1;
	int label = 0;
	while (preBigger > lastSmaller)
	{
		if (label == 0) posStart = posMid + 1;
		else posEnd = posMid - 1;
		posMid = (posStart + posEnd) >> 1;
		preBigger = 0;
		lastSmaller = 0;
		label = 0;
	}
	return true;
}