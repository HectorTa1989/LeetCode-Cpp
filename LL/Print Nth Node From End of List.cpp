struct Node 
{ 
  int data; 
  struct Node* next; 
}; 
  
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node *head, int n) 
{ 
  struct Node *main_ptr = head; 
  struct Node *ref_ptr = head; 
  
  int count = 0; 
  if(head != NULL) 
  { 
     while( count < n ) 
     { 
        if(ref_ptr == NULL) 
        { 
           printf("%d is greater than the no. of "
                    "nodes in list", n); 
           return; 
        } 
        ref_ptr = ref_ptr->next; 
        count++; 
     } /* End of while*/
  
     while(ref_ptr != NULL) 
     { 
        main_ptr = main_ptr->next; 
        ref_ptr  = ref_ptr->next; 
     } 
     printf("Node no. %d from last is %d ",  
              n, main_ptr->data); 
  } 
} 

//Method 2
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n) 
{ 
    int len = 0, i; 
    struct Node* temp = head; 
  
    // count the number of nodes in Linked List 
    while (temp != NULL) { 
        temp = temp->next; 
        len++; 
    } 
  
    // check if value of n is not 
    // more than length of the linked list 
    if (len < n) 
        return; 
  
    temp = head; 
  
    // get the (len-n+1)th node from the beginning 
    for (i = 1; i < len - n + 1; i++) 
        temp = temp->next; 
  
    cout << temp->data; 
} 
  
void push(struct Node** head_ref, int new_data) 
{ 
  /* allocate node */
  struct Node* new_node = new Node();  
  
  /* put in the data  */
  new_node->data  = new_data; 
  
  /* link the old list off the new node */
  new_node->next = (*head_ref);     
  
  /* move the head to point to the new node */
  (*head_ref)    = new_node; 
} 
  
/* Drier program to test above function*/
int main() 
{ 
  /* Start with the empty list */
  struct Node* head = NULL; 
  push(&head, 20); 
  push(&head, 4); 
  push(&head, 15); 
  push(&head, 35); 
  
  printNthFromLast(head, 4); 
} 