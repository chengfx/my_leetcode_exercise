#include"MergeTwoSortedLists.h"
#include<iostream>
using namespace std;


MergeTwoSortedLists::ListNode* MergeTwoSortedLists::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode node(0), *p = &node;
	while (l1&&l2)
	{
		if (l1->val <= l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	if (l1 == NULL && l2 != NULL)
		p->next = l2;
	else if (l1 != NULL && l2 == NULL)
		p->next = l1;
	return node.next;
}