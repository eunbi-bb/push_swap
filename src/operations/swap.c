/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:49 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/13 19:33:53 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
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
		ft_printf("sa\n");
	}
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
		ft_printf("sb\n");
	}
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
		ft_printf("ss\n");
	}
}
