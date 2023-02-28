#include "./push_swap.h"
#include <stdio.h>
/*push a : Take the first element at the top of b 
		and put it at the top of a.*/
void	pa(t_stack *stack)
{
	stack->size_a++;
	new_node(stack->b->data);
	add_after(); /*put the new node infront of stack A*/
	del_node();/*delete the first node from stack_b*/
	stack->size_b--;
	printf("pa\n");
}
/*push b : Take the first element at the top of a
		and put it at the top of b.*/
void	pb(t_stack *stack)
{
	stack->size_b++;
	new_node(stack->a->data);
	add_after();
	delnode();
	stack->size_a--;
	printf("pb\n");
}
