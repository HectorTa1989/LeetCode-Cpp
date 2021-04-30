//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//For example, Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* A) {
    if(!A || !A->next)
        return A;
        
    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = A;
    ListNode* prev = fakeHead;
    while (A)
    {
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (prev->next == A)
            prev = prev->next; 
        else 
            prev->next = A->next;
            
        A = A->next;
    }
    return fakeHead->next;
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-remove-duplicates-from-sorted_19.html
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        bool duplicate = false;
        
        while(cur) {
            if(cur->next && cur->val==cur->next->val) {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
                duplicate = true;
            }
            else if(duplicate) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
                duplicate = false;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};

//Recursion
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* runner = head->next;
        int count = 0;
        while(runner && runner->val==head->val) {
            runner = runner->next;
            count++;
        }
        ListNode* post = deleteDuplicates(runner);
        if (count > 0) return post;
        head->next = post;
        return head;
    }
};

//https://njuyangyang.gitbooks.io/leetcode-note/linear_table/Linked%20List/remove_duplicates_from_sorted_list_ii.html
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* current = head;
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* prev = &dummy;

        while(current != nullptr && current ->next != nullptr){
            if(current -> val == current -> next -> val){
                int value = current -> val;
                while(current != nullptr && current -> val == value){
                    prev -> next = current -> next;
                    ListNode* delptr = current;
                    delete delptr;
                    current = prev -> next;
                }
            }else{
                prev = current;
                current = current -> next;
            }
        }

        return dummy.next;

    }
};