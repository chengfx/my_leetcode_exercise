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
	if (((nums1Length == 0) && (nums2Length == 0)) || ((nums1Length + nums2Length) < kth))
	{
		*nums1Index = -1; *nums2Index = -1;
		return false;
	}
	else if (nums1Length == 0)
	{
		*nums1Index = -1; *nums2Index = kth;
		return false;
	}
	else if (nums2Length == 0)
	{
		*nums2Index = -1; *nums1Index = kth;
		return false;
	}
	//binary search
	int n1Start = 0, n1End = nums1Length - 1, n2Start = 0, n2End = nums2Length - 1;
	int n1pos = 0, n2Pos = 0;
	while ((n1Start < n1End) && (n2Start < n2End))
	{
		int n1Mid = (n1Start + n1End) >> 1, n2Mid = (n2Start + n2End) >> 1;
		int num = n1Mid + n2Mid + 2;
		if (kth < num)
		{
			//the array which has bigger number needs to change its  End index
			if (nums1[n1Mid] <= nums2[n2Mid]) 
				n2End = n2Mid - 1;
			else
				n1End = n1Mid - 1;
		}
		else
		{
			//the array which has smaller number needs to change its start index
			if (nums1[n1Mid] <= nums2[n2Mid])
				n1Start = n1Mid + 1;
			else
				n2Start = n2Mid + 1;
		}
		n1pos = n1Mid; n2Pos = n2Mid;
	}
	cout << "n1pos:" << n1pos << " n2pos:" << n2Pos << endl;
}