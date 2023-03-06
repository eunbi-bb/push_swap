#include "../../push_swap.h"

void	push_swap(char **argv)
{
	t_stack	*stack;
	int		size;
	int		i;
	int		tmp;

	i = 0;
	size = pusw_strlen(argv);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	stack->a = NULL;
	while (i < size)
	{
		tmp = pusw_atoi(argv[i], stack->a);
		if (!stack->a)
			stack->a = new_node(tmp);
		else
			add_after(stack->a, new_node(tmp));
		i++;  
		stack->a = stack->a->next;
	}
	stack->size_a = size;
	duplication_check(stack->a);
	sort(stack, size);
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
