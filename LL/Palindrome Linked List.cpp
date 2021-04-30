/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
	ListNode* slowp = head, *fastp = head, *revp = NULL;
	while (fastp && fastp->next){
		fastp = fastp->next->next;
		ListNode* tmp = slowp->next;
		slowp->next = revp;
		revp = slowp;
		slowp = tmp;
	}
	if (fastp) slowp = slowp->next;
	while (slowp && revp){
		if (slowp->val != revp->val) return false;
		slowp = slowp->next;
		revp = revp->next;
	}
	return true;
    }
};
//O(1) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow(head), *fast(head);
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next; // if odd, move one step forward
        // Reverse second half
        ListNode* pre(NULL), *cur(slow), *next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // Compare first half with reversed second half
        while(pre){
            if(pre->val != head->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
//
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev=nullptr, *next_node=nullptr, *dummy=nullptr;
        dummy = prev = new ListNode(-1);
		
		// find middle node
        while (fast && fast->next) {
            fast = fast->next->next;
            next_node = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next_node;
        }
		// skip middle node if the length of linked list is odd
        if (fast) slow = slow->next;
		
		// check equality
        while (slow && prev && slow->val == prev->val) {
            slow = slow->next;
            prev = prev->next;
        }
        return !slow && prev == dummy;
    }
};