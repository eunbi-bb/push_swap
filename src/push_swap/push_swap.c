#include "../../push_swap.h"

void	push_swap(char **argv)
{
	t_stack	*stack;
	t_node	*current;
	int		size;
	int		i;
	int		tmp;

	i = 0;
	size = pusw_strlen(argv);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	stack->a = NULL;
	current = NULL;
	while (i < size)
	{
		tmp = pusw_atoi(argv[i], stack->a);
		if (!stack->a)
		{
			stack->a = new_node(tmp);
			current = stack->a;
		}
		else
		{
			add_after(current, new_node(tmp));
			current = current->next;
		}
		i++;
	}
	stack->size_a = size;
	duplication_check(stack->a);
	printf("%d ", stack->a->data);
	printf("%d ", stack->a->next->data);
	printf("%d\n", stack->a->next->next->data);
	sort(stack, size);
	printf("%d ", stack->a->data);
	printf("%d ", stack->a->next->data);
	printf("%d\n", stack->a->next->next->data);
	free(stack->a);
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
	return(0);
}
