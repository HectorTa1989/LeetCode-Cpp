/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list. 
Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10*/

//Recursion
class Solution {
public:
    int gr = 0;
    int getDecimalValue(ListNode* head) {
        return head == NULL ? 0 : getDecimalValue(head->next) + (1<<gr++)*(head->val);
    }
};
//0ms 8.4mb	
int getDecimalValue(ListNode* head) {
        int res = 0;
        for (; head != NULL; head = head->next) res = (res * 2) + head->val;
        return res;
    }
//
int getDecimalValue(ListNode* head) {
        int num = 0;
        while(head) {
            num = (num << 1) + head->val;
            head = head->next;
        }
        return num;
    }
//
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result(0);
        while(head){
            result= result*2 + head->val;
            head=head->next;
        }
        return result;
    }
};
//
int getDecimalValue(ListNode* head) {
        int result(0);
        while(head){
            if(head->next) result=(result+head->val)*2;
            else if(head->val) result+=1;
            head=head->next;
        }
        return result;
    }

//Stack
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;
        if(curr==NULL)
            return 0;
        while(curr!=NULL)
        {
            s.push(curr->val);
            curr = curr->next;
        }
        int i = 0, num = 0;
        while(!s.empty())
        {
            int n = s.top();
            s.pop();
            if(n==1)
                num = num + pow(2, i);
            i++;
        }
        return num;
    }
};
