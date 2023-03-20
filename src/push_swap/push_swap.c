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

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*current;
	int		i;
	int		size;
	int		tmp;

	i = 0;
	stack = malloc(sizeof(t_stack));
	size = pusw_strlen(argv);
	if (!stack)
		return ;
	stack->a = NULL;
	stack->b = NULL;
	while (i < size)
	{
		tmp = pusw_atoi(argv[i], stack->a);
		if (!stack->a)
		{
			stack->a = new_node(tmp, -1);
			current = stack->a;
		}
		else
		{
			add_after(current, new_node(tmp, -1));
			current = current->next;
		}
		i++;
	}
	stack->size_a = size;
	duplication_check(stack->a);
	//print_stack(stack->a);
	sort(stack);
	//print_stack(stack->a);
	//print_stack(stack->b);
	free(stack);
}

void	leak_check(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	atexit(leak_check);
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	return(0);
}
