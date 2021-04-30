//https://leetcode.com/problems/add-two-numbers-ii/
//Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 8 -> 0 -> 7

//Method 1: Recursion
class Solution {
public:
    int add(ListNode* one ,ListNode* two ,int sone,int stwo,ListNode* &t){
        if(sone==0&&stwo==0)
            return 0;    
        int carry;
        int t1=0,t2=0;
        if(sone>stwo)
        {
            carry=add(one->next,two,sone-1,stwo,t);
            t1=one->val;
        }else if(sone<stwo){
            carry=add(one,two->next,sone,stwo-1,t);
            t2=two->val;
        }else{
            carry=add(one->next,two->next,sone-1,stwo-1,t);
            t1=one->val;
            t2=two->val;
        }
        int data = t1+t2+carry;
        ListNode* nn = new ListNode(data%10);
        nn->next=t;
        t=nn;
        return data/10;
    }
    
    ListNode* addTwoNumbers(ListNode* one, ListNode* two) {
        ListNode* t= one;
        int sone=0;
        while(t!=NULL){
            sone++;
            t=t->next;
        }
        t=two;
        int stwo=0;
        while(t!=NULL){
            stwo++;
            t=t->next;
        }
        t=NULL;
        int carry = add(one,two,sone,stwo,t);
        if(carry){
            ListNode* nn = new ListNode(carry);
            nn->next=t;
            t=nn;
        }
        return t;
    }
};

//Method 2: Stack
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> stackL1,stackL2;
		while(l1){
			stackL1.push(l1->val);
			l1=l1->next;
		}
		while(l2){
			stackL2.push(l2->val);
			l2=l2->next;
		}

		ListNode *dummy=new ListNode(0);
		dummy->next=NULL;
		int carry = 0,num1,num2;

		while (!stackL1.empty() || !stackL2.empty() || carry) {
			if(!stackL1.empty()){
				num1=stackL1.top();
				stackL1.pop();
			}else num1=0;

			if(!stackL2.empty()){
				num2=stackL2.top();
				stackL2.pop();
			}else num2=0;

			int sum = num1 + num2 + carry;
			int value = sum % 10;
			carry = sum / 10; //进位

			ListNode *newNode=new ListNode(value);
			newNode->next=dummy->next;
			dummy->next = newNode;
		}

		ListNode *retNode=dummy->next;
		delete dummy;
		return retNode;
	}
};