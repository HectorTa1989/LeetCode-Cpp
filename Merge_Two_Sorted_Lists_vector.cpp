#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int N = 0;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if(!l1 && !l2)
		return NULL;
	vector<int> v;
	
	while(l1)
	{
		v.push_back(l1->val);
		l1 = l1->next;
	}
	while(l2)
	{
		v.push_back(l2);
		l2 = l2->next;
	}
	sort(v.begin(), v.end());
	l1 = new ListNode(0);
	l2 = l1;
	for (auto val : v ) {
		l2->next = new ListNode(val);
		l2 = l2->next;
	}
	return l1->next;	
}