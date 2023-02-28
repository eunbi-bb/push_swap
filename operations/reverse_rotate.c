#include "../push_swap.h"
#include <stdio.h>

t_node	*to_tail(t_node *node)
{
	while (node->next != NULL)
	{
		node++;
	}
	return (node);
}

/*reverse rotate a : Shift down all elements of stack a by 1.*/
void	rra(t_stack *stack)
{
	int	tmp;

	if (stack->size_a >= 2)
	{
		to_tail(stack->a);
		tmp = stack->a->data;
		while (stack->a->prev != NULL)
		{
			stack->a->data = stack->a->prev->data;
			stack->a--;
		}
		stack->a->prev->data = tmp;
		printf("rra\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");
}
/*reverse rotate b : Shift down all elements of stack b by 1.*/
void	rrb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b >= 2)
	{
		to_tail(stack->b);
		tmp = stack->b->data;
		while (stack->b->prev != NULL)
		{
			stack->b->data = stack->b->prev->data;
			stack->b--;
		}
		stack->b->prev->data = tmp;
		printf("rrb\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");
}

/*rra and rrb at the same time.*/
void	rrr(t_stack *stack)
{
	int	tmp;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		to_tail(stack->a);
		tmp = stack->a;
		while (stack->a->prev != NULL)
		{
			stack->a->data = stack->a->prev->data;
			stack->a--;
		}
		stack->a->prev->data = tmp;
		to_tail(stack->b);
		tmp = stack->b;
		while (stack->b->prev != NULL)
		{
			stack->b->data = stack->b->prev->data;
			stack->b--;
		}
		stack->b->prev->data = tmp;
		printf("rrr\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");
}
