#include"UniqueBinarySearchTreesII.h"
#include<cmath>

void UniqueBinarySearchTreesII::example()
{
	generateTrees(3);
}
TreeNode* UniqueBinarySearchTreesII::clone(TreeNode* treePtr)
{
	if (treePtr == nullptr)
		return nullptr;
	TreeNode* newRoot = new TreeNode(treePtr->val);
	newRoot->left = clone(treePtr->left);
	newRoot->right = clone(treePtr->right);
	return newRoot;
}

vector<TreeNode*> UniqueBinarySearchTreesII::generateTrees(int n)
{
	vector<TreeNode*> res;
	if (n <= 0) return res;
	res.push_back(new TreeNode(1));
	for (int i = 2; i <= n; ++i)
	{
		vector<TreeNode*> temp;
		for (int j = 0; j < res.size(); ++j)
		{
			//i as root;
			TreeNode* oldRoot = res[j];
			TreeNode* newNode = new TreeNode(i);
			newNode->left = oldRoot;
			temp.push_back(clone(newNode));
			// insert i in tree
			TreeNode* tempRoot = oldRoot;
			while (tempRoot != nullptr)
			{
				TreeNode* right = tempRoot->right;
				tempRoot->right = newNode;
				newNode->left = right;
				temp.push_back(clone(oldRoot));
				tempRoot->right = newNode ->left;
				tempRoot = tempRoot->right;
			}
			delete newNode;
		}
		res = temp;
	}
	return res;
}