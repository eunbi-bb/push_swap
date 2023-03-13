#include "../../push_swap.h"

int	get_min(t_node *stack)
{
	t_node	*tmp;
	t_node	*min;

	if (!stack)
		return (0);
	tmp = stack;
	min = stack;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->data);
}

int	get_max(t_node *stack)
{
	t_node	*tmp;
	t_node	*max;

	if (!stack)
		return (0);
	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->data);
}