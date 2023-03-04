#include "../../push_swap.h"

void	push_swap(char **argv)
{
	t_stack	*stack;
	int		size;
	int		i;

	i = 0;
	size = pusw_strlen(argv);
	stack = malloc(sizeof(t_node));
	while (i < size)
	{
		add_after(stack->a, new_node(*argv[i]));
		i++;
		stack->a = stack->a->next;
	}
	stack->size_a = size;
	duplication_check(stack->a);
	sort(stack, size);
	free(stack->a);
	free(stack->b);
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
