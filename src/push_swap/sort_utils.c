#include "../../push_swap.h"

t_node	*get_min(t_node *stack, long lower_limit)
{
	t_node	*tmp;
	t_node	*min;
	int min_value;

	if (!stack)
		return (0);
	tmp = stack; 
	min = stack;
	min_value = 2147483647;
	while (tmp)
	{
		if ((tmp->data <= min_value) && (tmp->data > lower_limit))
		{
			min_value = tmp->data;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

unsigned int	get_max(t_node *stack)
{
	t_node	*tmp;
	t_node	*max;

	if (!stack)
		return (0);
	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->index);
}

void	put_index(t_stack *stack)
{
	int		i;
	long	lowest;
	t_node	*min;

	lowest = -2147483649;
	i = 0;
	while (i < stack->size_a)
	{
		min = get_min(stack->a, lowest);
		min->index = i;
	printf("giving index : %d to %d\n", i, min->data);
		lowest = min->data;
		i++;
	}
}

/*Check out if the stack is sorted.
return 1 if it is sorted. Otherwise 0.*/
int	sort_check(t_stack *stack)
{
	t_node	*tmp;
	int		prev_value;

	if (!stack)
		return(1);
	tmp = stack->a;
	prev_value = tmp->data;
	while (tmp)
	{
		if (tmp->data < prev_value)
			return (0);
		prev_value = tmp->data;
		tmp = tmp->next;
	}
	return(1);
}
