class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
		// move fast pointer to the n + 1 element
        while (n--) { fast = fast->next; }
        
        // handle edge case: given n is always valid, 
        // if fast reached the end, we need to remove the first element
        if (fast == nullptr) return head->next;

        // move both pointers at the same time maintaing the difference
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow will be pointing to the element before the one we want to remove
        slow->next = slow->next->next;
        
        return head;
    }
};

//
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow(head), *fast(head);
        while(n--) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next) slow = slow->next, fast = fast->next;
        slow->next = slow->next->next;
        return head;
    }
};


// by shchshhappy
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n == 0) return head;

        struct ListNode *p0 = head, *p1= head;
        int cnt = 0;
        while (p0->next != NULL) {
            ++cnt;
            p0 = p0->next;
            if (cnt > n)
                p1 = p1->next;
        }

        if (cnt == n - 1) return head->next;

        p1->next = p1->next->next;
        return head;
    }
};

//by kun596
ListNode *removeNthFromEnd(ListNode *head, int n) 
{
    if (!head)
        return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_de_deleted = slow->next;
    slow->next = slow->next->next;
    
    delete to_be_deleted;

    return new_head.next;
}
//by mfab
 ListNode* node = head, *offsetNode = head;
    for (int i = 0; i < n; ++i)
        node = node->next;
    
    // if node is NULL n is equal to the length of the linked list and we have to remove the head
    if (node == NULL)
        return head->next;
    
    while (node->next != NULL) {
        node = node->next;
        offsetNode = offsetNode->next;
    }
    
    offsetNode->next = offsetNode->next->next;
    
    return head;