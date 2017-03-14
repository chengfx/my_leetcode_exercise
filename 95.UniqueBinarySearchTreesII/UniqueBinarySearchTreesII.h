#pragma once

#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class UniqueBinarySearchTreesII
{
public:
	void example();
	vector<TreeNode*> generateTrees(int n);
	TreeNode* clone(TreeNode*);
};