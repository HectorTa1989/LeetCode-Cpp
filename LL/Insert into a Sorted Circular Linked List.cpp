class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node *pre = head, *cur = pre->next;
        while (cur != head) {
            if (pre->val <= insertVal && cur->val >= insertVal) break;
            if (pre->val > cur->val && (pre->val <= insertVal || cur->val >= insertVal)) break;
            pre = cur;
            cur = cur->next;
        }
        pre->next = new Node(insertVal, cur);
        return head;
    }
};

/*The insertion position is within 3 condition,

1. cur go through a round back to head.

2.  cur.val <= insertVal <= cur.next.val

3. insertVal super max or insertVal super small, insert into the fall down position.

Note: Pay attention to corner case, head == null. DO NOT forget to have cur = cur.next in while loop.

Time Complexity: O(n). n = circular length.

Space: O(1).*/
class Solution {
      Node* insert(Node* head, int insertVal) {
         Node* res = new Node(insertVal);
         if(head == null){
             res->next = res;
             return res;
         }
         
         Node* cur = head;
         while(cur->next != head 
               && !((cur->val <= insertVal && insertVal <= cur->next->val) 
                    || (cur->val > cur->next->val && (cur->next->val > insertVal || cur->val < insertVal)))){
             cur = cur-.next;
         }
         
         res->next = cur->next;
         cur->next = res;
         return head;
     }
 };