#include"MergeSortedArray.h"

void MergeSortedArray::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	--m; --n;
	int len = m + n + 1;
	while (m >= 0 && n >= 0)
	{
		if (nums1[m] >= nums2[n])
		{
			nums1[len] = nums1[m];
			--m;
		}
		else
		{
			nums1[len] = nums2[n];
			--n;
		}
		--len;
	}
	if (m < 0)
		while (len >= 0)
			nums1[len--] = nums2[n--];
}