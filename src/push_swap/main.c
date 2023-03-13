#include "../../push_swap.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;
	int		size;

	size = 3;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 3;
	stack->size_b = 3;

	stack->a = new_node(3);
	add_after(stack->a, new_node(2));
	add_after(stack->a->next, new_node(5));
	
	stack->b = new_node(8);
	add_after(stack->b, new_node(9));
	add_after(stack->b->next, new_node(7));
	t_node *temp = stack->a;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	temp = stack->b;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	//pa(stack);
	pb(stack);

	temp = stack->a;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	temp = stack->b;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return(0);
}

	//rra(stack);
	//rrb(stack);
	// rrr(stack);
	//sa(stack);
	//sb(stack);
	//ss(stack);
	//ra(stack);
	//rb(stack);
	// rr(stack);
	
