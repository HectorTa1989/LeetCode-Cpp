//Recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp;
        temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        
        return temp;
    }
};

// iteratively
ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0), *node;
    node = dummy;
    dummy->next = head;
    while (head && head->next) {
        ListNode *nxt = head->next;
        head->next = nxt->next;
        nxt->next = head;
        node->next = nxt;
        node = head;
        head = node->next;
    }
	delete dummy;
    return dummy->next;
}

// Swap method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next)) return head;
	ListNode* prev = head;
	ListNode* cur = head->next;
	while(prev && cur)
	{
		int temp;
		temp = prev->val;
		prev->val = cur->val;
		cur->val = temp;
		
		if(cur->next == NULL || cur->next->next == NULL)
			break;
		
		prev = cur->next;
		cur = cur->next->next;
		 
	}
	return head;	
    }
};

// Another iterative solution
/*Well, since the head pointer may also been modified, we create a new_head that points to it to facilitate the swapping process.

For the example list 1 -> 2 -> 3 -> 4 in the problem statement, it will become 0 -> 1 -> 2 -> 3 -> 4 (we init new_head -> val to be 0). Then we set a pointer pre to new_head and another cur to head. Each time, we will swap pre -> next and cur -> next using the following piece of code.

pre -> next = cur -> next;
cur -> next = cur -> next -> next;
pre -> next -> next = cur;
After swapping them, we update as follows:

pre = cur; 
cur = pre -> next; 
to swap the next two nodes.

Finally, we return new_head -> next.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) { 
        if (!head || !(head -> next)) return head;
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head; 
        ListNode* cur = head;
        while (pre -> next && cur -> next) {
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = cur;
            pre = cur;
            cur = pre -> next;
        }
        return new_head -> next;
    }
};