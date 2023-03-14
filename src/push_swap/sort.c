#include "../../push_swap.h"

/*1. 1 3 2
  2. 2 1 3
  3. 2 3 1
  4. 3 1 2
  5. 3 2 1
*/
void	sort_aaa(t_stack *stack)
{
	int	one;
	int	two;
	int	three;

	one = stack->a->data;
	two = stack->a->next->data;
	three = stack->a->next->next->data;
	if (one < two && one < three && two > three)
	{
		sa(stack);
		ra(stack);
	}
	else if (one > two && one < three && two < three)
		sa(stack);
	else if (one < two && one > three && two > three)
		rra(stack);
	else if (one > two && one > three && two < three)
		ra(stack);
	else if (one > two && one > three && two > three)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_by_min(t_stack *stack)
{
	unsigned int	min_index;

	while (stack->size_a > 3)
	{
		min_index = get_min(stack->a, -2147483649)->index;
		while (stack->a->index > min_index)
			ra(stack);
		pb(stack);
	}
	sort_aaa(stack);
	while (stack->b)
		pa(stack);
}

void	sort_by_max(t_stack *stack)
{
	while (stack->size_a > 3)
	{
		while (stack->a->index < get_max(stack->a))
			ra(stack);
		pb(stack);
	}
	sort_aaa(stack);
	while (stack->b)
	{
		pa(stack);
		ra(stack);
	}
}

void	find_fastest(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack->a;
	i = 0;
	while (tmp->index < get_max(stack->a))
	{
		i++;
		tmp = tmp->next;
	}
	if	(i < stack->size_a / 2)
		sort_by_max(stack);
	else
		sort_by_min(stack);
}

void	sort(t_stack *stack)
{
	if (!sort_check(stack))
	{
		put_index(stack);
		if (stack->size_a <= 5)
		{
			if (stack->size_a == 3)
				sort_aaa(stack);
			else if (stack->size_a == 2)
				sa(stack);
			else
				find_fastest(stack);
		}
		else
			radix(stack, stack->size_a);
	}
}