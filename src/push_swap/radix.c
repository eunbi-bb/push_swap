#include "../../push_swap.h"

void	radix(t_stack *stack, int size)
{
	int	i;
	unsigned int	bit;
	t_node			*current;

	bit	= 0;
	while (bit < 32)
	{
		i = 0;
		current = stack->a;
		while (i < size)
		{
			if ((1 & (current->index >> bit)) == 0)
				pb(stack);
			else
				ra(stack);
			current = stack->a;
			i++;
		}
		current = stack->b;
		while (stack->b)
			pa(stack);
		bit++;
		if (sort_check(stack))
			return ;
	}
}