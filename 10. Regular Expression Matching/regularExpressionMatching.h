#pragma once

#include<string>

class regularExpressionMatching {
public:
	void example();
	bool isMatch(std::string s, std::string p);
	bool DP(std::string s, std::string p);
};