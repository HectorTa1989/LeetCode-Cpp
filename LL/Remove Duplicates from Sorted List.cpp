//https://www.techiedelight.com/remove-duplicates-linked-list/
/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* cur = head;
        if(!head || !(head->next)) return head;
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val)                
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};
//

#include <iostream>
#include <unordered_set>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to print given linked list
void printList(Node* head)
{
	Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "null";
}

// Helper function to insert a new node in the beginning of the linked list
void push(Node** headRef, int data)
{
	Node* newNode = new Node();

	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

// Function to remove duplicates from a sorted list
void RemoveDuplicates(Node* head)
{
	Node* previous = nullptr;
	Node* current = head;

	// take an empty set to store linked list nodes for future reference
	unordered_set<int> set;

	// do till linked list is not empty
	while (current != nullptr)
	{
		// if current node is seen before, delete it
		if (set.find(current->data) != set.end())
		{
			previous->next = current->next;
			delete current;
		}
		else
		{
			// insert current node into the set and proceed to next node
			set.insert(current->data);
			previous = current;
		}
		current = previous->next;
	}
}

//Method 2
Node* RemoveDuplicates(Node* head)
{
	if(head == NULL) return head;
	Node* cur = head;
	
	while(cur->next != NULL)
	{
		if(cur->data == cur->next->data)
		{
			Node* temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
		cur = cur->next;
	}
	return head;
}

// main method to remove remove duplicates from list
int main()
{
	// input keys
	int keys[] = {5, 3, 4, 2, 5, 4, 1, 3};
	int n = sizeof(keys)/sizeof(keys[0]);

	// points to the head node of the linked list
	Node* head = nullptr;

	// construct linked list
	for (int i = n-1; i >= 0; i--)
		push(&head, keys[i]);

	RemoveDuplicates(head);

	// print linked list
	printList(head);

	return 0;
}


//Method 2
void removeDuplicateNode(Node *head)
{
	Node *cur = head;
	Node *prev;
	Node *dup;
	
	while(cur != NULL && cur->next != NULL)
	{
		prev = cur;
		while(prev->next != NULL)
		{
			if(cur->data == prev->next->data)
			{
				dup = prev->next;
				prev->next = prev->next->next;
				delete dup;
			}
			else
				prev = prev->next;
		}
		cur = cur->next;
	}
}


//
struct Node
{
	int data;
	Node *next;
}

void removeDuplicates(Node *head)
{
	Node *cur = head;
	Node *following;
	
	while(cur->next != NULL)
	{
		if(cur->data == cur->next->data)
		{
			following = cur->next->next;
			delete (cur->next);
			cur->next = following;
		}
		cur = cur->next;
	}
}

// recursive method
void removeDuplicates(Node *head)
{
	Node *to_free;
	if(head == NULL)
		return;
		
	if(head->next != NULL)
	{
		if(head->data == head->next->data)
		{
			to_free = head->next;
			head->next = head->next->next;
			delete to_free;
			removeDuplicates(head);
		}
		removeDuplicates(head->next);
	}
}