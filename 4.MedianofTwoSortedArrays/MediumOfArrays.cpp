#include "MediumOfArrays.h"
#include <iostream>
using namespace std;

void MediumOfArrays::example()
{
	vector<int> nums1 = {3};
	vector<int> nums2 = {1,2,4 };
	int a = 0, b = 0;
	cout << "result is :" << findMedianSortedArrays(nums1, nums2) << endl;
	cout << "result is :" << findMedianSortedArrays1(nums1, nums2) << endl;
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

double MediumOfArrays::findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2)
{
	int nums1Index, nums2Index;
	int length = nums1.size() + nums2.size();
	bool isOdd = length & 1;
	int kth = (length + 1) >> 1;
	GetKthNumber(nums1, &nums1Index, nums2, &nums2Index, kth);
	double medium;
	int last1 = nums1Index + 1 < nums1.size() ? nums1[nums1Index + 1] : (0x7fffffff);
	int last2 = nums2Index + 1 < nums2.size() ? nums2[nums2Index + 1] : (0x7fffffff);
	int min = (last1 >= last2) ? last2 : last1;
	if (nums1Index < 0) 
		medium = isOdd ? nums2[nums2Index] : static_cast<double>(nums2[nums2Index] + min) / 2;
	else if (nums2Index < 0)
		medium = isOdd ? nums1[nums1Index] : static_cast<double>(nums1[nums1Index] + min) / 2;
	else {
		int max = nums2[nums2Index] > nums1[nums1Index] ? nums2[nums2Index] : nums1[nums1Index];
		medium = isOdd ? max : static_cast<double>(max + min) / 2;
	}
	return medium;
}

bool MediumOfArrays::GetKthNumber(vector<int>& nums1, int* nums1Index, vector<int>& nums2, int* nums2Index,int kth)
{
	int nums1Length = nums1.size(), nums2Length = nums2.size();
	*nums1Index = -1; *nums2Index = -1;
	//critical condition
	if (kth > (nums1Length + nums2Length)) return false;
	if (kth == (nums1Length + nums2Length))
	{
		*nums1Index = nums1Length - 1; 
		*nums2Index = nums2Length - 1;
		return true;
	}
	if ((nums2Length == 0) || (kth <= nums1Length && nums1[kth - 1] <= nums2[0]))
	{
		*nums1Index = kth - 1;
		return true;
	}
	if ((nums1Length == 0) || (kth <= nums2Length && nums2[kth - 1] <= nums1[0]))
	{
		*nums2Index = kth - 1;
		return true;
	}
	//inital
	vector<int>::iterator min, max;
	int minStart = 0, minEnd, maxEnd, indexLength = kth - 2;
	int *minIndex, *maxIndex;
	if (nums1Length <= nums2Length)
	{
		min = nums1.begin(); max = nums2.begin();
		minEnd = nums1Length - 1; maxEnd = nums2Length - 1;
		minIndex = nums1Index; maxIndex = nums2Index;
	}
	else
	{
		min = nums2.begin(); max = nums1.begin();
		minEnd = nums2Length - 1; maxEnd = nums1Length - 1;
		minIndex = nums2Index; maxIndex = nums1Index;
	}
	int preBigger, lastSmaller, label = 0;
	*minIndex = indexLength <= maxEnd ? -1 : indexLength - maxEnd - 1;
	//search;
	do
	{
		if (label == 0) minStart = *minIndex + 1;
		else minEnd = *minIndex - 1;
		*minIndex = (minStart + minEnd) >> 1;
		*maxIndex = indexLength - *minIndex;
		preBigger = (min[*minIndex] >= max[*maxIndex]) ? min[*minIndex] : max[*maxIndex];
		if (*minIndex == minEnd)
			lastSmaller = preBigger;
		else if (*maxIndex >= maxEnd)
		{
			lastSmaller = min[*minIndex + 1];
			label = 0;
		}
		else
		{
			int minI = *minIndex + 1, maxI = *maxIndex + 1;
			label = min[minI] >= max[maxI];
			lastSmaller = label ? max[maxI] : min[minI];
		}
	} while (preBigger > lastSmaller);
	return true;
}

