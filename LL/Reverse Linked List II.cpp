class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
	   delete dummy;
       return dummy -> next;
   }
};

//Method 2
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m<1 || m>=n || !head) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        // move head to (m-1)th node
        for(int i=0; i<m-1; i++)
            head = head->next;
        
        // reverse list from pre with length n-m+1    
        ListNode *pre = head->next, *cur = pre->next;
        for(int i=0; i<n-m; i++) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        head->next->next = cur;
        head->next = pre;
        head = dummy->next;
        delete dummy;
        return head;
    }
};

//Method 3
//The solution reverses elements within the range [m, n] one by one. The slow and fast pointers never move. 
//"slow“ stays one element before the beginning and ”fast“ stays at the end of the reversed part. "tmp" is used to point to the element that will be moved from the end 
//to the beginning in each iteration, it is the only pointer that moves. With #(n-m) iterations, we get the result.
//This example shows how the list changes in each iteration and pointer status after it:

//Input 1->2->3->4->5->6, m = 2, n = 5

//1->3->2->4->5->6, slow@1, fast@2, tmp@3
//1->4->3->2->5->6, slow@1, fast@2, tmp@4
//1->5->4->3->2->6, slow@1, fast@2, tmp@5

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy;
        n -= m;
        while (--m)
            slow = slow->next;
        ListNode *fast = slow->next, *tmp;
        while (n--) {
            tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return dummy.next;
    }
};

//by StefanPochmann
ListNode* reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(0), *prev = &dummy;
    dummy.next = head;
    for (int i=1; i<m; i++)
        prev = prev->next;
    ListNode *pivot = prev->next;
    for (int i=m; i<n; i++) {
        swap(prev->next, pivot->next->next);
        swap(prev->next, pivot->next);
    }
    return dummy.next;
}
//by StefanPochmann update
ListNode* reverseBetween(ListNode *head, int m, int n) {
    ListNode **prev = &head;
    for (int i=1; i<m; i++)
        prev = &(*prev)->next;
    ListNode *pivot = *prev;
    for (int i=m; i<n; i++) {
        swap(*prev, pivot->next->next);
        swap(*prev, pivot->next);
    }
    return head;
}