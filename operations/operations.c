// #include "push_swap.h"

// /*swap a : Swap the first 2 elements at the top of stack a.*/
// void	sa(t_stack *stack)
// {
// 	t_node	*tmp;

// 	if (stack->size_a >= 2)
// 	{
// 		tmp = stack->a->next;
// 		stack->a->next = tmp->next;
// 		tmp->next->prev = stack->a;
// 		tmp->next = stack->a;
// 		tmp->prev = NULL;
// 		stack->a->prev = tmp;
// 		stack->a = tmp;
// 	}
// }
// /*swap b : Swap the first 2 elements at the top of stack b.*/
// void	sb(t_stack *stack)
// {
// 	t_node	*tmp;

// 	if (stack->size_b >= 2)
// 	{
// 		tmp = stack->b->next;
// 		stack->b->next = tmp->next;
// 		tmp->next->prev = stack->b;
// 		tmp->next = stack->b;
// 		tmp->prev = NULL;
// 		stack->b->prev = tmp;
// 		stack->b = tmp;
// 	}
// }
// /*sa and sb at the same time.*/
// void	ss(t_stack *stack)
// {
// 	sa(stack);
// 	sb(stack);
// }

// /********************************/
// /*push a : Take the first element at the top of b and put it at the top of a.*/
// void	pa(t_stack *stack)
// {
// 	t_node	*tmp;
	
// 	if (stack->size_b >= 1)
// 	{
// 		tmp = stack->b;
// 		stack->b = tmp->next;
// 		tmp->next->prev = NULL;
// 		tmp->next = stack->a;
// 		tmp->prev = NULL;
// 		stack->a->prev = tmp;
// 		stack->a = tmp;
// 		stack->size_a++;
// 		stack->size_b--;	
// 	}
// }
// /*push b : Take the first element at the top of a and put it at the top of b.*/
// void	pb(t_stack *stack)
// {
// 	t_node	*tmp;

// 	if (stack->size_a >= 1)
// 	{
// 		tmp = stack->a;
// 		stack->a = tmp->next;
// 		tmp->next->prev = NULL;
// 		tmp->next = stack->b;
// 		tmp->prev = NULL;
// 		stack->b->prev = tmp;
// 		stack->b = tmp;
// 		stack->size_b++;
// 		stack->size_a--;
// 	}
// }
// /*******************************/
// /*rotate a : Shift up all elements of stack a by 1.*/
// void	ra(t_stack *stack)
// {
// 	t_node	*head;

// 	if (stack->size_a <= 1)
// 		return ;
// 	head = stack->a;
// 	stack->a = stack->a->next;
// 	//stack->a->prev = NULL;
// 	while (stack->a->next != NULL)
// 	{
// 		stack->a = stack->a->next;
// 	}
// 	stack->a->next = head;
// 	head->prev = stack->a;
// 	head->next = NULL;
// }
// /*rotate b : Shift up all elements of stack b by 1.*/
// void	rb(t_stack *stack)
// {
// 	t_node	*head;
	
// 	if (stack->size_b <= 1)
// 		return ;
// 	head = stack->b;
// 	stack->b = stack->b->next;
// 	while (stack->b->next != NULL)
// 	{
// 		stack->b = stack->b->next;
// 	}
// 	stack->b->next = head;
// 	head->prev = stack->b;
// 	head->next = NULL;
// }
// /*ra and rb at the same time.*/
// void	rr(t_stack *stack)
// {
// 	ra(stack);
// 	rb(stack);
// }
// /******************************/
// /*reverse rotate a : Shift down all elements of stack a by 1.*/
// void	rra(t_stack *stack)
// {
// 	t_node	*tail;

// 	if (stack->size_a <= 1)
// 		return ;
// 	tail = stack->a;
// 	while (tail->next != NULL)
// 	{
// 		tail = tail->next;
// 	}
// 	tail->next = stack->a;
// 	stack->a->prev = tail;
// 	stack->a->next = NULL;
// }
// /*reverse rotate b : Shift down all elements of stack b by 1.*/
// void	rrb(t_stack *stack)
// {
// 	t_node	*tail;

// 	if (stack->size_b <= 1)
// 		return ;
// 	tail = stack->b;
// 	while (tail->next != NULL)
// 	{
// 		tail = tail->next;
// 	}
// 	tail->next = stack->b;
// 	stack->b->prev = tail;
// 	stack->b->next = NULL;
// }
// /*rra and rrb at the same time.*/
// void	rrr(t_stack *stack)
// {
// 	rra(stack);
// 	rrb(stack);
// }