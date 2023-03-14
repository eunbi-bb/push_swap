/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:49 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/14 09:20:49 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*swap a : Swap the first 2 elements at the top of stack a.*/
void	sa(t_stack *stack)
{
	int tmp_data;
	int tmp_index;

	if (stack->size_a >= 2)
	{
		tmp_data = stack->a->data;
		tmp_index = stack->a->index;
		stack->a->data = stack->a->next->data;
		stack->a->index = stack->a->next->index;
		stack->a->next->data = tmp_data;
		stack->a->next->index = tmp_index;
		ft_printf("sa\n");
	}
}
/*swap b : Swap the first 2 elements at the top of stack b.*/
void	sb(t_stack *stack)
{
	int tmp_data;
	int tmp_index;

	if (stack->size_b >= 2)
	{
		tmp_data = stack->b->data;
		tmp_index = stack->b->index;
		stack->b->data = stack->b->next->data;
		stack->b->index = stack->b->next->index;
		stack->b->next->data = tmp_data;
		stack->b->next->index = tmp_index;
		ft_printf("sb\n");
	}
}

void	ss(t_stack *stack)
{
	int tmp_data;
	int tmp_index;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tmp_data = stack->a->data;
		tmp_index = stack->a->index;
		stack->a->data = stack->a->next->data;
		stack->a->index = stack->a->next->index;
		stack->a->next->data = tmp_data;
		stack->a->next->index = tmp_index;
		tmp_data = stack->b->data;
		tmp_index = stack->b->index;
		stack->b->data = stack->b->next->data;
		stack->b->index = stack->b->next->index;
		stack->b->next->data = tmp_data;
		stack->b->next->index = tmp_index;
		ft_printf("ss\n");
	}
}
