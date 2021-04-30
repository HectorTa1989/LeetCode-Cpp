#include <bits/stdc++.h>

using namespace std;
const int N = 0;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *start, *cur;

        if (l1->val < l2->val) {
            cur = start = l1;
            l1 = l1->next;
        } else {
            cur = start = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;
        return start;
    }
};

// Better 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0); //  ListNode *newHead(0) don't need to delete newHead 
        ListNode *cur = newHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == 0 ? l2 : l1;
		delete newHead;
        return newHead->next;
    }
};

// Method 2: 4ms cpp solution using recursion
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {    
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
*/

ListNode *l1, *l2, *ll1, *ll2;
int main() {
    int n1, n2;
    Solution s;
    cin >> n1;
    ll1 = l1 = new ListNode(0);
    for (int i = 0; i < n1; i++) {
        l1->next = new ListNode(0);
        l1 = l1->next;
        scanf("%d", &(l1->val));
    }
    cin >> n2;
    ll2 = l2 = new ListNode(0);
    for (int i = 0; i < n2; i++) {
        l2->next = new ListNode(0);
        l2 = l2->next;
        scanf("%d", &(l2->val));
    }
    ListNode *res = s.mergeTwoLists(ll1->next, ll2->next);
    while (res != NULL) {
        cout << res->val << ' ';
        res = res->next;
    }

    return 0;
}

//by Atomsktron
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    if(!l1)         // If no l1, return l2
        return l2;
    if(!l2)         // If no l2, return l1
        return l1;
    if(!l2 && !l1)  // If neither, return NULL;
        return NULL;
        
    ListNode* head; // The pointer we will use to construct a merged list
    
    
    if(l1->val < l2->val)   // If l1 less than l2
    {
        head = l1;          // We start at l1
        l1 = l1->next;      // and iterate l1
    }
    else                    // If l2 less than l1
    {
        head = l2;          // We start at l2
        l2 = l2->next;      // and iterate l2
    }
    
    ListNode* ret = head;   // We need to save the addres of the head of the list
    
    while(l1 && l2)         // While both input lists have values
    {
        if(l1->val < l2->val)   // Compare the current values, if l1 is less
        {
            head->next = l1;    // Append the merged list with l1's current address
            l1 = l1->next;      // Advance l1
        }
        else                    // Else, l2 had the low value
        {
            head->next = l2;    // Append l2 to the list
            l2 = l2->next;      // Advance l2
        }
        head->next->next = NULL;    // Append a NULL teminator to the list
        head = head->next;          // Advance the merged list
    }
    
    // Lastly, if list were different lengths, we need to append the longer list tail to the merged list
    
    if(l1)
        head->next = l1;
    else if(l2)
        head->next = l2;
        
    return ret; // Return the starting address of head that we saved.
    
    
}