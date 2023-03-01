/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:41 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/01 15:19:44 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	int		tmp;
	t_node	*current;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tmp = stack->a->data;
		current = stack->a;
		while (current->next != NULL)
		{
			current->data = current->next->data;
			current = current->next;
		}
		current->data = tmp;
		tmp = stack->b->data;
		current = stack->b;
		while (current->next != NULL)
		{
			current->data = current->next->data;
			current = current->next;
		}
		current->data = tmp;
		printf("rr\n");
	}
	else
		printf("rr: Less than 2 numbers in stacks.\n");
}
