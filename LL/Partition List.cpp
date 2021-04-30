/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
the list is like [1,4,3,2,5,2] and x = 3, then the output will be [1,2,2,4,3,5]*/

//
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode right(0);
        ListNode* l = &left;
        ListNode* r = &right;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                l->next = cur;
                l = l->next;
            }
            else{
                r->next = cur;
                r = r->next;
            }
            cur = cur->next;
        }
        r->next = NULL;
        l->next = right.next;
        return left.next;
    }
};

//
Node* PartitionList(Node* head, int x)
{
	Node* before_head = new Node(0);
	Node* before = before_head;
	Node* after_head = new Node(0);
	Node* after = after_head;
	
	while(head)
	{
		if(head->val < x)
		{
			before->next = head;
			before = before->next;
		}
		else
		{
			after->next = head;
			after = after->next;
		}
		head = head->next;
	}
	after->next = NULL;
	before->next = after_head->next;
	
	delete before_head;
	delete after_head;
	
	return before_head->next;
}

//
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* low=NULL;
        ListNode* high=NULL;
        ListNode* temp1;
        ListNode* temp2;
        while(temp)
        {
            if(temp->val<x)
            {
                if(low)
                {
                    temp1->next=temp;
                }
                else
                {
                    low=temp;
                }
                temp1=temp;
                temp=temp->next;
                temp1->next=NULL;
            }
            else
            {
                if(high)
                {
                    temp2->next=temp;
                }
                else
                {
                    high=temp;
                }
                
                temp2=temp;
                temp=temp->next;
                temp2->next=NULL;
            }
        }
        if(low && temp1)
            temp1->next=high;
        else if(!low && high)
            low=high;
        return low;
    }
};