Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

/*Enumerate through the list to find the last node, count the size along the way.
Make a loop, by connection last to first
Get modulo of |k/size| - avoiding extra rotation
Enumerate again size-k nodes
Break the loop and return new head*/

 ListNode *rotateRight(ListNode *head, int k) 
     {
        if(head == NULL || head->next == NULL||k==0) return head;
        
        ListNode* node = head;
        int size =1;
        
        while(node->next != NULL)
        {
            size++;
            node = node->next;
        }
        
        //loop the list
        node->next=head;
        
        //handle the case of k>size
        k = k%size;
        
        //find the node to break the loop at
        while(--size >= k)
        {
            node=node->next;
        }
        
        ListNode* first = node->next;
        node->next=NULL;
        
        return first;
    }
	
//Sol 2
//In the first For loop, I make p1 point to tail node and count the size of this linked list. Then p1->next = head make this list become a circle.
//In the second For loop, I make p2 point to the previous node before the target node. Let the previous node point to nullptr and return target node.
//Tricky place: size - k % size - 1 can make pointer point to the previous node before the target node in O(n) time.

ListNode *rotateRight(ListNode *head, int k) {
    if(head == nullptr){
        return nullptr;
    }
    ListNode* p1 = head;
    ListNode* p2 = head;
    int size = 1;
    while(p1->next != nullptr){
        p1 = p1->next;
        size++;
    }
    p1->next = head;
    for(int i = 0; i < size - k % size - 1; i++){
        p2 = p2->next;
    }
    p1 = p2->next;
    p2->next = nullptr;
    return p1;
}

//Sol 3
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    int l = 0;
    ListNode *node = head;
    while (node) {
        l++;
        node = node->next;
    }
    if (!head || k%l == 0)
        return head;
    k %= l;
    ListNode *fast, *slow;
    fast = slow = head;
    for (int i = 0; i < k; i++)
        fast = fast->next;
    while (fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *res = slow->next;
    slow->next = NULL;
    fast->next = head;
    return res;
}
};
//Sol 4: https://njuyangyang.gitbooks.io/leetcode-note/linear_table/Linked%20List/rotate_list.html
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr) return head;

        int count = 0;

        ListNode* temp = head;
        while(temp -> next != nullptr){
            count++;
            temp = temp -> next;
        }        

        count++;
        temp -> next = head;

        int step = count - k % count;

        for(int i = 0; i < step; i++){
            temp = temp -> next;
        }

        ListNode* newhead = temp -> next;
        temp -> next = nullptr;

        return newhead;
    }
};