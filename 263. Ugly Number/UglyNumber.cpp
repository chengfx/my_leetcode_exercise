#include "UglyNumber.h"
#include <iostream>
using namespace std;

void UglyNumber::example()
{
	UglyNumber test;
	cout << test.isUgly1(5) << endl;
}

bool UglyNumber::isUgly(int num)
{
	// parameter checking
	if (num < 1)
		return false;
	//divide by 2
	while ((num & 0x01) == 0)
		num >>= 1;
	//divide by 3
	int temp = num / 3;
	while (temp * 3 == num)
	{
		num = temp;
		temp /= 3;
	}
	//divide by 5
	temp = num / 5;
	while (temp * 5 == num)
	{
		num = temp;
		temp /= 5;
	}
	return (num == 1) ? true : false;
}

bool UglyNumber::isUgly1(int num)
{
	if (num < 1) return false;
	while (num % 2 == 0) num >>= 1;
	while (num % 3 == 0) num /= 3;
	while (num % 5 == 0) num /= 5;
	return (num == 1);
}