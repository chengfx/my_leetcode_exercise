#include"ComplexNumberMultiplication.h"
#include<iostream>
#include<stdlib.h>

using namespace std;

void ComplexNumberMultiplication::example()
{
	cout << complexNumberMultiply("1+1i", "-1+-1i") << endl;
}

string ComplexNumberMultiplication::complexNumberMultiply(string a, string b)
{
	const char* aStr = a.c_str();
	const char* bStr = b.c_str();
	int aFirst = atoi(aStr);
	const char* temp = aStr;
	while (*temp != '+') ++temp;
	int aSecond = atoi(temp + 1);
	int bFirst = atoi(bStr);
	temp = bStr;
	while (*temp != '+') ++temp;
	int bSecond = atoi(temp + 1);
	int rFirst = aFirst*bFirst - aSecond*bSecond;
	int rSeond = aFirst*bSecond + aSecond*bFirst;
	cout << aFirst << aSecond << endl;
	cout << bFirst << bSecond << endl;
	string result = to_string(rFirst) + '+' + to_string(rSeond) + 'i';
	return result;
}