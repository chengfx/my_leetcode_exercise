#include"ReverseInterger.h"
#include <iostream>
using namespace std;

void ReverseInterger::example()
{
	int result = reverse(2147483647);
	cout << "result: " << result << endl;
}

int ReverseInterger::reverse(int x)
{
	int flag = x & (1 << 31);
    x = flag ? (~x + 1) : x;
	int result = 0;
	while (x)
	{
		int temp = (result << 3) + (result << 1) + x % 10;
		if (temp / 10 != result)
			return 0;
		result = temp;
		x /= 10;
	}
	return flag ? (~result + 1) : result;
}
