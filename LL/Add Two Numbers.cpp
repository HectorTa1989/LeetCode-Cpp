//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. 
//Add the two numbers and return it as a linked list.
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while(l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            sum += val1 + val2;
            cur->next = new ListNode(sum % 10);
            sum /= 10;
            cur = cur->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if(sum)
            cur->next = new ListNode(sum);
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-add-two-numbers.html
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0), *p = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            if(l1) {
                carry+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry+=l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry%10);
            carry /= 10;
            p = p->next;
        }
		ListNode* tmp = dummy->next;
		delete dummy;
        return tmp;
    }
};