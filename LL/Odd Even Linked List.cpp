/*Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL*/

//Solution 1
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* odd = head, *evenHead = head->next, *even = head->next;
        while (even != NULL && even->next != NULL) {
            odd = odd->next = even->next;
            even = even->next = even->next->next;
        }
        odd->next = evenHead;
        return head;
    }
};
//Solution 2
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *oddPointer = head;
        ListNode *evenPointer = head->next;
        ListNode *even = head->next;
        
        while(evenPointer != nullptr && evenPointer->next != nullptr){
            oddPointer->next = oddPointer->next -> next;
            oddPointer = oddPointer->next;
            evenPointer->next = evenPointer->next -> next;
            evenPointer = evenPointer->next;
        }
        oddPointer->next = even;
        return head;
    }
};
/*EXPLANATION:-
Take a list of nodes 
    1 ->  2 -> 3 -> 4 -> 5 -> null
	  
    We need to modify this list.
	as all odd nodes followed by all even nodes.
	  
	We can get required list, 
	if we can seperate nodes at odd places as one list
	and nodes at even places as one list.
	And at the end, if we merge those two list,
	we will get the required list.
	
	odd list  (which contain all nodes in odd places) -   1 -> 3 -> 5 
	even list  (which contain all nodes in even places) -   2 -> 4 -> null
	
    We can do this by taking two pointers
	  1. odd pointer  -> which iterates over nodes in odd places
	  2. even pointer  -> which iterates over nodes in even places
	
	How can we get these two lists?
	
	Take two pointers:-
	oddPointer points to first node in the list since 1 is odd.
	evenPointer points to second node in the list.
	
	Now, oddPointer and evenPointer contain these nodes.
	oddPointer :- 1 -> 2 -> 3 -> 4 -> 5 -> null
	evenPointer :-  2 -> 3 -> 4 -> 5 -> null
	odd head :- 1 -> 2 -> 3 -> 4 -> 5 -> null
	even head :-  2 -> 3 -> 4 -> 5 -> null
	
	using oddPointer and evenPointers, 
	move two steps forward by deleting next node
	
	After 1st iteration:-
	oddPointer:- 3 -> 4 -> 5 -> null
	evenPointer:- 4 -> 5 -> null
	-> 2 is deleted in odd list
	odd head :- 1 -> 3 -> 4 -> 5 -> null
	-> 3 is deleted in even list
	even head :- 2 -> 4 -> 5 ->null
	
	Again, delete next Node and move two steps
	oddPointer:-  5 -> null
	evenPointer:- null
	-> 4 is deleted in odd list
	odd head :- 1 -> 3 -> 5 -> null
	-> 5 is deleted in even list
	even head :- 2 -> 4 -> null
	
	Do this process until evenPointer reaches to null
	because evenPointer is one step ahead than oddPointer.
	
	Now, we have two lists
	odd list :- 1 -> 3 -> 5 -> null
	even list  :- 2 -> 4 -> null
	
	Now, merge these two lists.
	
	result :- 1 -> 3 -> 5 -> 2 -> 4  -> null
	
	return result.
	
	Now, By doing above process,
	Let's develop an algorithm to solve this problem.
	
	1. Take two pointers oddPointer and evenPointer
	    and maintain head pointers too.
	2. Now, Do below process until evenPointer becomes null
	       Delete one node in odd list
		   Move two steps forward.
		   Delete one node in even list
		   Move two steps forward.
    3. Now, merge odd and even lists.
        This can be done by this line.
		oddPointer.next = even_head;
		oddPointer points to last node in the odd list
		we need to add even list at the end of add list.
	4. return resultant list.
	
	IF YOU HAVE ANY DOUBTS, FEEL FREE TO ASK
	IF YOU UNDERSTAND, DON'T FORGET TO UPVOTE.
	
	IF YOU WANT MORE ANSWERS, PLEASE FOLLOW ME.
	
	TIME:- O(N)
	SPACE:- O(1)*/