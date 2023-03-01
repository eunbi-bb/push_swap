#include "../push_swap.h"
#include <stdio.h>
/*push a : Take the first element at the top of b 
		and put it at the top of a.*/
void	pa(t_stack *stack)
{
	stack->size_a++;
	add_after(stack->a, new_node(stack->b->data));
	if (stack->b && stack->b->next)
		del_node(&stack->b, &stack->b->next, stack->b);
	stack->size_b--;
	printf("pa\n");
}
/*push b : Take the first element at the top of a
		and put it at the top of b.*/
void	pb(t_stack *stack)
{
	stack->size_b++;
	add_after(stack->b, new_node(stack->a->data));
	if (stack->a && stack->a->next)
		del_node(&stack->a, &stack->a->next, stack->a);
	stack->size_a--;
	printf("pb\n");
}
