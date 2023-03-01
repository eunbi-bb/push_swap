/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:49 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/01 15:19:51 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

/*swap a : Swap the first 2 elements at the top of stack a.*/
void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a >= 2)
	{
		tmp = stack->a->data;
		stack->a->data = stack->a->next->data;
		stack->a->next->data = tmp;
		printf("sa\n");
	}
	else
		printf("sa: Less than 2 numbers in stack A.\n");
}
/*swap b : Swap the first 2 elements at the top of stack b.*/
void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b >= 2)
	{
		tmp = stack->b->data;
		stack->b->data = stack->b->next->data;
		stack->b->next->data = tmp;
		printf("sb\n");
	}
	else
		printf("sb: Less than 2 numbers in stack B.\n");
}

void	ss(t_stack *stack)
{
	int tmp;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tmp = stack->a->data;
		stack->a->data = stack->a->next->data;
		stack->a->next->data = tmp;
		tmp = stack->b->data;
		stack->b->data = stack->b->next->data;
		stack->b->next->data = tmp;
		printf("ss\n");
	}
	else
		printf("ss: Less than 2 numbers in the stacks.");
}
