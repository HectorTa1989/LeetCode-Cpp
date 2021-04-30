class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //divide the list into two parts 
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dump(0);
        ListNode* cur = &dump;
        
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
                
            cur = cur->next;
        }
        
        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;
            
        return dump.next;
    }
};

//
ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == NULL)
        return head;
    ListNode *fast = head->next->next, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *r = sortList(slow->next);
    slow->next = NULL;
    ListNode *l = sortList(head);
    return merge(l, r);
}

ListNode *merge(ListNode *l, ListNode *r) {
    ListNode *dummy = new ListNode(0), *node;
    node = dummy;
    while (l && r) {
        if (l->val < r->val) {
            node->next = l;
            l = l->next;
        } else {
            node->next = r;
            r = r->next;
        }
        node = node->next;
    }
    if (l)
        node->next = l;
    else 
        node->next = r;
    return dummy->next;
}