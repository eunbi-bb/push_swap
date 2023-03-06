#include "../../push_swap.h"

int	q_sort_a(t_stack *stack, t_node start, t_node end)
{
	int	pivot;
	int item;

	if (sort_check(stack, ASCENDING) == 1)
		return (1);
	item = stack->size_a;
	if (stack->size_a <= 3)
	{
		sort_aaa(stack);
		return (1);
	}
	if ()
}
