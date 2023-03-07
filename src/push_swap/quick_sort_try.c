#include "../../push_swap.h"

void	quick_sort_3(t_stack *stack, int size)
{
	if (size == 3 && stack->size_a == 3)
		sort_aaa(stack);
	else if (size == 2)
	{
		if (stack->a->data > stack->a->next->data)
			sa(stack);
	}
	else if (size == 3)
	{
		while (size != 3 || !(stack->a->data < stack->a->next->data
			&& stack->a->next->data < stack->a->next->next->data))
		{
			if (size == 3 || stack->a->data > stack->a->next->data && stack->a->next->next->data)
				sa(stack);
			else if (size = 3 && !(stack->a->next->next->data > stack->a->data && stack->a->next->next->data > stack->a->next->data))
				size = ft_push(stack, size, 0);
			else if (stack->a->data > stack->a->next->data)
				sa (stack);
			else if (size++)
				pa(stack);
		}
	}
}
/*void is possible?*/
int	sort_small_b(t_stack *stack, int size)
{
	if (size == 1)
		pa(stack);
	else if (size == 2)
	{
		if (stack->b->data < stack->b->next->data)
			sb(stack);
		while (size--)
			pa(stack);
	}
	else if (size == 3)
	{
		while (size || !(stack->a->data < stack->a->next->data && stack->a->next->data < stack->a->next->next->data))
		{
			if (size == 1 && stack->a->data > stack->a->next->data)
				sa(stack);
			else if (size == 1 || (size >= 2 && stack->b->data > stack->b->next->data)
				|| (size == 3 && stack->b->data > stack->b->next->next->data))
				size = ft_push(stack, size, 1);
			else
				sb(s);
		}
	}
	return (0);
}

int	quicksort_a(t_stack *stack, int size, int cnt)
{
	int	pivot;
	int	items;

	if (sort_check(stack->a, size, ASCENDING) == 1)
		return (1);
	items = size;
	if (size <= 3)
	{
		quick_sort_3(stack, size);
		return (1);
	}
	if (!cnt && !get_median(pivot->data, stack->a, size))
		return (0);
	while (size != items / 2 + items % 2)
	{
		if (stack->a->data < pivot && (size--))
			pb(stack);
		else if (++cnt)
			ra(stack);
	}
	while (items / 2 + items % 2 != stack->size_a &&cnt--)
		rra(stack);
	return(quicksort_a(stack, items / 2 + items % 2, 0))
		&& quicksort_b(stack, items / 2, 0);
	return (1);
}

int	quicksort_a(t_stack *stack, int size, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && sort_check(stack->b, size, DESCENDING) == 1)
		while (size--)
			pa(stack);
	if (size <= 3)
	{
		sort_small_b(stack, size);
		return (1);
	}
	items = size;
	if (!get_median(&pivot, stack->b, size))
		return (0);
	while (size != items / 2)
	{
		if (stack->b->data >= pivot && size--)
			pa(stack);
		else if (cnt++)
			rb(stack);
	}
	while (items / 2 != stack->size_b && cnt--)
		rrb(stack);
	return (quicksort_a(stack, items / 2 + items % 2, 0) && quicksort_b(stack, items / 2, 0));
}