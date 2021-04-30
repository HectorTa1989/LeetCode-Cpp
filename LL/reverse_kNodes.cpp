Node *reverse(Node **head, int k)
{
	Node *cur = *head;
	Node *prev = NULL;
	
	while(cur && k--)
	{
		Node *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

Node *