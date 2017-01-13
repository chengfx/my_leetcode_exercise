#include"StringtoInteger.h"
#include<iostream>
using namespace std;

void StringtoInteger::example()
{
	StringtoInteger str;
	int result = str.myAtoi(string("     -1234000"));
	cout << "result is :" << (result) << endl;
}
int StringtoInteger::myAtoi(std::string str)
{
	int strLength = str.size();
	if (strLength == 0)
		return 0;
	int index = 0;
	while (str[index] == ' ') ++index;
	bool positive = true;
	if (str[index] == '-') {
		positive = false;
		++index;
	}
	else if (str[index] == '+')
		++index;
	int num = 0;
	while ((index < strLength) && (str[index] >= '0') && (str[index] <= '9'))
	{
		int temp = str[index] - '0';
		//calculate number
		temp = num * 10 + temp;
		//judge if overflow
		if (temp / 10 != num)
			return positive ? INT_MAX : INT_MIN;
		num = temp;
		++index;
	}
	num = positive ? num : (~num + 1);
	return num;
}