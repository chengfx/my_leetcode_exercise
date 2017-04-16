#include "PalindromeNumber.h"
#include <iostream>
#include <string>

using namespace std;
void PalindromeNumber::example()
{
	cout << isPalindrome(1212) << endl;;
}

bool PalindromeNumber::isPalindrome(int x) 
{
	if (x & 0x80000000)
		return false;
	int base = 1;
	int temp = x;
	while (temp /= 10)
		base *= 10;
	int rightBase = 1;
	while (rightBase < base)
	{
		int left = x / base;
		int right = x / rightBase;
		if ((left % 10) != (right % 10))
			return false;
		rightBase *= 10;
		base /= 10;
	}
	return true;
}