/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:56 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/14 09:22:38 by eunbi         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*reverse rotate a : Shift down all elements of stack a by 1.*/
void	rra(t_stack *stack)
{
	int		tmp;
	t_node	*tail;

	if (stack->size_a >= 2)
	{
		tail = lst_last(stack->a);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		ft_printf("rra\n");
	}
}
/*reverse rotate b : Shift down all elements of stack b by 1.*/
void	rrb(t_stack *stack)
{
	int		tmp;
	t_node	*tail;

	if (stack->size_b >= 2)
	{
		tail = lst_last(stack->b);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		ft_printf("rrb\n");
	}
}

/*rra and rrb at the same time.*/
void	rrr(t_stack *stack)
{
	int		tmp;
	t_node	*tail;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tail = lst_last(stack->a);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		tail = lst_last(stack->b);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		ft_printf("rrr\n");
	}
}
