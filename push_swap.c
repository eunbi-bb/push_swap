#include "push_swap.h"

t_node	*new_node(int data)
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
	return (new_node);
}

void	add_after(t_node *before, t_node *new_node)
{
	t_node	*head;
	t_node	*tail;

	if (before == NULL && head == NULL)
	{
		head = new_node;	
		tail = new_node;
	}
	else if (before == NULL)
	{
		new_node->next = head;
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

void	push_swap(char **argv)
{
	t_stack	stack;
	int		size;
	int		i;

	i = 0;
	size = pusw_strlen(argv);
	stack.a = malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free(stack.a);
		return;
	}
	stack.size_b = 0;
	while (i++ < size)
		stack.a->data = pusw_atoi(argv[i], stack.a);
	duplication_check(stack.a, size);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	else
	{
		ft_printf("Not enough arguments to sort.\n");
		return (0);
	}
}
