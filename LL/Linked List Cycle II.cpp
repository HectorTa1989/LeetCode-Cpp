/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //Floyd Cycle algorithm
 /*
1. the straight path before the cycle in the linked list is of length : x
2. the place where slow and fast meet is y distance from the start of the cycle
3. there are z steps left to reach the start of the cycle again from the meeting place

slow pointer : travels x + y distance to meet the fast pointer

fast pointer : travels (x + y + (z + y)) distance to meet the slow pointer [reason : (x + y) to reach the meeting place, 
but it again goes around the loop and meets it on its way back, so (z + y) steps are needed]

But the fast pointer travels at speed 2 times that of slow pointer

So, 2(x + y) = (x + 2y + z)
=> x = z

This is an extremely powerful result, which means that the distance between the start of the linked list and the start of the cycle, 
x is equal to the distance between the start of the cycle and the meeting point, z.

So, if slow walks at a step of 1 each time from the head of the list, and if fast walks at a pace of 1 step each time. 
They are to meet at the start of the cycle, because slow will travel x steps and fast will travel z steps.*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow = head, *fast = head;
        bool dup = false;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                dup = true;
                break;
            }
        }
        if(!dup) return NULL;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
//Size of the loop :
int lengthCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                flag = true;
                break;
            }
        }
        if(!flag)
            return 0;
        int steps = 1;
        fast = fast->next;
        while(slow != fast){
            fast = fast->next;
            steps ++;
        }
        return steps;
    }

//http://bangbingsyb.blogspot.com/2014/11/leetcode-linked-list-cycle-i-ii.html
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *slow = head, *fast = head;
        
        do {
            if(!fast->next || !fast->next->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while(slow!=fast);
        
        slow = head;
        while(slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

//https://medium.com/@ChYuan/leetcode-no-142-linked-list-cycle-ii-%E5%BF%83%E5%BE%97-medium-c5b53dcca804
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
	ListNode* FastNode = head;
	ListNode* SlowNode = head;

	while(true) {
	if (FastNode != NULL && FastNode->next != NULL) {
	SlowNode = SlowNode->next;
	FastNode = FastNode->next->next;
	} 
	else
		return NULL;
	if (SlowNode == FastNode)
	break;
	}
	while(SlowNode != head) {
	SlowNode = SlowNode->next;
	head = head->next;
	}
	return head;
	}
};

//https://leetcode.com/problems/linked-list-cycle-ii/discuss/44913/Straight-Forward-C%2B%2B-Solution-with-Explanation-by-using-2-Pointers-(16ms)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *p1=head;
        ListNode *p2=head;
        int count=0;    //using count to record the length of cycle, if it exists.
        while(p1&&p2){
            count++;
            p1=p1->next;
            p2=p2->next;
            if(p2!=NULL) p2=p2->next;
            if(p1==p2&&p1&&p2){
                p1=head;
                p2=head;
                //make the distance between p1 and p2 be the length of cycle
                //when p1 and p2 meet at the first time, this postion will be the start node of the cycle.
                for(int i=0;i<count;i++) p2=p2->next;   
                while(p1!=p2){
                    p1=p1->next;
                    p2=p2->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};