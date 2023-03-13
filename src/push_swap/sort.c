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

static void	sort_by_min(t_stack *stack, int size)
{
	t_node *tmp;

	while (size > 3)
	{
		tmp = get_min(stack->a, -2147483649);
		while (stack->a->data > tmp->data)
			ra(stack);
		pb(stack);
		size--;
	}
	sort_aaa(stack);
	while (stack->b)
		pa(stack);
}

static void	sort_by_max(t_stack *stack, int size)
{
	while (size > 3)
	{
		while (stack->a->data > get_max(stack->a))
			ra(stack);
		pb(stack);
		size--;
	}
	sort_aaa(stack);
	while (stack->b)
	{
		pa(stack);
		ra(stack);
	}
}

static void	find_fastest(t_stack *stack, int size)
{
	t_node	*tmp;
	int		i;

	tmp = stack->a;
	i = 0;
	while (tmp->data < get_max(stack->a))
	{
		i++;
		tmp = tmp->next;
	}
	if	(i < size / 2)
		sort_by_min(stack, size);
	else
		sort_by_max(stack, size);
}


void	sort(t_stack *stack, int size)
{
	if (!sort_check(stack))
	{
		put_index(stack);
		if (size <= 5)
		{
			if (size == 2)
				sa(stack);
			else if (size == 3)
				sort_aaa(stack);
			else
				find_fastest(stack, size);
		}
		else
			radix(stack, size);
	}
}