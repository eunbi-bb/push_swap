#include "../../push_swap.h"

t_node	*lst_last(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*lst_front(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_node	*new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_after(t_node *before, t_node *new_node)
{
	t_node	*head;
	t_node	*tail;

	head = lst_front(before);
	tail = lst_last(before);
	if (before == NULL)
	{
		new_node->next = head;
		if (head)
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
}

void	del_node(t_node **head, t_node **tail, t_node *p)
{
	if (*head == NULL || p == NULL)
		return ;
	if (p == *head)
	{
		*head = p->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		else
			*tail = NULL;
	}
	else if (p == *tail)
	{
		*tail = p->prev;
		if (*tail != NULL)
			(*tail)->next = NULL;
		else
			*head = NULL;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	free(p);
}