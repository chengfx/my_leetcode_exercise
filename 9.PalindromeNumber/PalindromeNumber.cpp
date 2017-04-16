#include "PalindromeNumber.h"
#include <iostream>
#include <string>

using namespace std;
void PalindromeNumber::example()
{
	cout << isPalindrome(1221) << endl;;
}

bool PalindromeNumber::isPalindrome(int x) 
{
	if (x & 0x80000000 || (x != 0 && x % 10 == 0))
		return false;
	int temp = 0;
	while (x > temp)
	{
		temp *= 10;
		temp += x % 10;
		x /= 10;
	}
	return x == temp || x == (temp/10);
}