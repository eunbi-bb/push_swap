#include "../../push_swap.h"

void	print_stack(t_node *stack)
{
	t_node *temp = stack;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

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
	stack->b = NULL;
	current = NULL;
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
	sort(stack, size);
	//print_stack(stack->a);
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
