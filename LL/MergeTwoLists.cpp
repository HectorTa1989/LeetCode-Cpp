Node *mergeTwoLists(Node *l1, Node *l2)
{
	Node *head = new Node(0);
	Node *cur = head;
	
	while(l1 && l2)
	{
		if(l1->data <= l2->data)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
		
	cur->next = (l1 == 0 ? l2 : l1);
	
	Node *temp = head->next;
	delete head;
	return temp;
}