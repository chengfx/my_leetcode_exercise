#include "UglyNumber2.h"
#include <iostream>
#include <algorithm>
using namespace std;

void UglyNumber2::example()
{
	UglyNumber2 test;
	cout << test.nthUglyNumber(10) << endl;
}

int UglyNumber2::nthUglyNumber(int n)
{
	if (n <= 1) return 1;
	int* uglyNumberArray = new int[n];
	int count = 0, t2 = 0, t3 = 0, t5 = 0;
	uglyNumberArray[count++] = 1;
	while (count < n)
	{
		int temp2 = uglyNumberArray[t2] * 2;
		int temp3 = uglyNumberArray[t3] * 3;
		int temp5 = uglyNumberArray[t5] * 5;
		uglyNumberArray[count] = min(min(temp2, temp3), temp5);
		while (uglyNumberArray[t2] * 2 <= uglyNumberArray[count]) ++t2;
		while (uglyNumberArray[t3] * 3 <= uglyNumberArray[count]) ++t3;
		while (uglyNumberArray[t5] * 5 <= uglyNumberArray[count]) ++t5;
		++count;
	}
	int nthNumber = uglyNumberArray[count - 1];
	delete[] uglyNumberArray;
	return nthNumber;
}