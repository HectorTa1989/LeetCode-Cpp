/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.*/

//Method 1
/*Suppose we have a list [1,2,3,4,5,6,7]

Steps as follow:

Divide the list into front list: [1,2,3,4] and tail list: [5,6,7]
Reverse the tail list to [7,6,5]
Join front and tail list,
   1      ->2      ->3      ->4
     ->7       ->6      ->5
Result: [1,7,2,6,3,5,4]*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow = head, *fast = head;
        ListNode* pre = new ListNode(0);
        pre->next = slow;
        while(fast && fast->next){
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next, pre = pre->next;
        pre->next = NULL;
        ListNode* cur, *next;
        pre = NULL, cur = slow;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode* h1 = head, *h2 = pre, *p1, *p2;
        while(h1 && h2){
            p1 = h1->next;
            p2 = h2->next;
            h1->next = h2;
            h2->next = p1;
            h1 = p1;
            h2 = p2;
        }
    }
};
//Sol 2
class Solution {
public:
    void reorderList(ListNode* head) {
    if (!head || !(head->next))
        return;
    ListNode *fast = head->next, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *cur = slow->next, *node = NULL;
    slow->next = NULL;
    while (cur) {
        ListNode *nxt = cur->next;
        cur->next = node;
        node = cur;
        cur = nxt;
    }
    while (node) {
        ListNode *nxt1 = head->next, *nxt2 = node->next;
        head->next = node;
        node->next = nxt1;
        head = nxt1;
        node = nxt2;
    }
}
};
//Sol 3
//Step1. get the mid Node of the list
//Step2. reverse the second half list
//Step3. merge the two half lists
class Solution {
public:
    void reorderList(ListNode *head) {
		if (!head) return;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p1 = &dummy, *p2 = &dummy;
		for (; p2 && p2->next; p1 = p1->next, p2 = p2->next->next);
		for ( ListNode *prev = p1, *curr = p1->next; curr && curr->next; ){
			ListNode *tmp = curr->next;
			curr->next = curr->next->next;
			tmp->next = prev->next;
			prev->next = tmp;
		}
		for ( p2 = p1->next, p1->next = NULL,p1 = head; p2; ){
			ListNode *tmp = p1->next;
			p1->next = p2;
			p2 = p2->next;
			p1->next->next = tmp;
			p1 = tmp;
		}
    }
};