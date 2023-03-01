#include "../push_swap.h"
#include <stdio.h>

/*rotate a : Shift up all elements of stack a by 1.*/
void	ra(t_stack *stack)
{
	int	tmp;
	t_node	*current;

	if (stack->size_a >= 2)
	{
		tmp = stack->a->data;
		current = stack->a;
		while (current->next != NULL)
		{
			current->data = current->next->data;
			current = current->next;
		}
		current->data = tmp;
		printf("ra\n");
	}
	else
		printf("ra: Less than 2 numbers in stack A.\n");
}
		//printf("stack->a : %d | stack->a->next : %d\n", stack->a->data, stack->a->next->data);
/*rotate b : Shift up all elements of stack b by 1.*/
void	rb(t_stack *stack)
{
	int	tmp;
	t_node	*current;

	if (stack->size_b >= 2)
	{
		tmp = stack->b->data;
		current = stack->b;
		while (current->next != NULL)
		{
			current->data = current->next->data;
			current = current->next;
		}
		current->data = tmp;
		printf("rb\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");

}

/*ra and rb at the same time.*/
void	rr(t_stack *stack)
{
	int	tmp;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tmp = stack->a->data;
		while (stack->a->next != NULL)
		{
			stack->a->data = stack->a->next->data;
			stack->a = stack->a->next;
		}
		stack->a->data = tmp;
		tmp = stack->b->data;
		while (stack->b->next != NULL)
		{
			stack->b->data = stack->b->next->data;
			stack->b = stack->b->next;
		}
		stack->b->data = tmp;
	}
	else
		printf("rr: Less than 2 numbers in stacks.\n");
}
