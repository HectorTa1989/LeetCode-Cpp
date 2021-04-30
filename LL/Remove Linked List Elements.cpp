//Remove all elements from a linked list of integers that have value val.

//Input:  1->2->6->3->4->5->6, val = 6
//Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                ListNode* tmp = cur->next->next;
                cur->next->next = NULL;
                cur->next = tmp;
            }
            else
                cur = cur->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};