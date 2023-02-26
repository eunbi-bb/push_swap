void	add_after(t_node *before, int data)
{
	t_node	*new_node;
	t_node	*head;
	t_node	*tail;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (before == NULL && head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else if (before == NULL)
	{
		new_node->next = head;
		head->prev = new_node;
	}
	else if (before == tail)
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		new_node->prev = before;
		new_node->next = before->next;
		before->next->prev = new_node;
		before->next = new_node;
	}
	size++;
}

void	del_node(t_node *head, t_node *tail, t_node *p)
{
	if (head == NULL || p == NULL)
		return (0);
	if (p == head)
	{
		head = p->next;
		if (head != NULL)
			head->prev = NULL:
	}
	else if (p == tail)
	{
		tail = p->prev;
		if (tail != NULL)
			tail->next = NULL;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	free (p);
}
