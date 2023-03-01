/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:19:56 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/01 15:35:09 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_node	*to_tail(t_node *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

/*reverse rotate a : Shift down all elements of stack a by 1.*/
void	rra(t_stack *stack)
{
	int		tmp;
	t_node	*tail;

	if (stack->size_a >= 2)
	{
		tail = to_tail(stack->a);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		printf("rra\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");
}
/*reverse rotate b : Shift down all elements of stack b by 1.*/
void	rrb(t_stack *stack)
{
	int		tmp;
	t_node	*tail;

	if (stack->size_b >= 2)
	{
		tail = to_tail(stack->b);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		printf("rrb\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");
}

/*rra and rrb at the same time.*/
void	rrr(t_stack *stack)
{
	int		tmp;
	t_node	*tail;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		tail = to_tail(stack->a);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		tail = to_tail(stack->b);
		tmp = tail->data;
		while (tail->prev != NULL)
		{
			tail->data = tail->prev->data;
			tail = tail->prev;
		}
		tail->prev = NULL;
		tail->data = tmp;
		printf("rrr\n");
	}
	else
		printf("rb: Less than 2 numbers in stack B.\n");
}
