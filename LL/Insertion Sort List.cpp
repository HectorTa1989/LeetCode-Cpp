//Keep a sorted partial list (head) and start from the second node (head -> next), 
//each time when we see a node with val smaller than its previous node, 
//we scan from the head and find the position that the node should be inserted. 
//Since a node may be inserted before head, we create a dummy head that points to head.
//8ms
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if ((cur -> next) && (cur -> next -> val < cur -> val)) {
                while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
                    pre = pre -> next;
                }
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                pre = dummy;
            }
            else {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};
//52ms
ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *h = insertionSortList(head->next);
    if (head->val <= h->val) {  // first case
        head->next = h;
        return head;
    }
    ListNode *node = h;   // second case
    while (node->next && head->val > node->next->val)
        node = node->next;
    head->next = node->next;
    node->next = head;
    return h;
}