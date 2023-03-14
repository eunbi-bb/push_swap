/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:41 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/14 13:18:10 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotation(t_node *current, int tmp_data, int tmp_index)
{
	while (current->next != NULL)
	{
		current->data = current->next->data;
		current->index = current->next->index;
		current = current->next;
	}
	current->data = tmp_data;
	current->index = tmp_index;
}

/*rotate a : Shift up all elements of stack a by 1.*/
void	ra(t_stack *stack)
{
	int tmp_data;
	int tmp_index;
	t_node	*current;

	if (stack->size_a >= 2)
	{
		tmp_data = stack->a->data;
		tmp_index = stack->a->index;
		current = stack->a;
		rotation(current, tmp_data, tmp_index);
		ft_printf("ra\n");
	}
}
		//ft_printf("stack->a : %d | stack->a->next : %d\n", stack->a->data, stack->a->next->data);
/*rotate b : Shift up all elements of stack b by 1.*/
void	rb(t_stack *stack)
{
	int tmp_data;
	int tmp_index;
	t_node	*current;

	if (stack->size_b >= 2)
	{
		tmp_data = stack->b->data;
		tmp_index = stack->b->index;
		current = stack->b;
		rotation(current, tmp_data, tmp_index);
		ft_printf("rb\n");
	}
}

/*ra and rb at the same time.*/
void	rr(t_stack *stack)
{
	int tmp_data;
	int tmp_index;
	t_node	*current;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tmp_data = stack->a->data;
		tmp_index = stack->a->index;
		current = stack->a;
		rotation(current, tmp_data, tmp_index);
		tmp_data = stack->b->data;
		tmp_index = stack->b->index;
		current = stack->b;
		rotation(current, tmp_data, tmp_index);
		ft_printf("rr\n");
	}
}
