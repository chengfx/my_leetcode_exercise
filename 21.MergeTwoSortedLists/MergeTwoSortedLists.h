#pragma once

class MergeTwoSortedLists
{
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(0) {}

	};

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};