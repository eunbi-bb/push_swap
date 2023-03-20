/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 14:24:30 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/20 18:43:33 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*lst_last(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*lst_front(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

void	push_swap(t_stack *stack, char **argv, int size)
{
	int		i;
	int		tmp;
	t_node	*current;

	i = 0;
	while (i < size)
	{
		tmp = pusw_atoi(argv[i], stack->a);
		if (!stack->a)
		{
			stack->a = new_node(pusw_atoi(argv[i], stack->a), -1);
			current = stack->a;
		}
		else
		{
			add_after(current, new_node(tmp, -1));
			current = current->next;
		}
		i++;
	}
	stack->size_a = size;
	duplication_check(stack->a);
	sort(stack);
	free(stack);
}

void	leak_check(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		size;
	atexit(leak_check);
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		size = pusw_strlen(argv);
		stack = malloc(sizeof(t_stack));
		if (!stack)
			return (0);
		stack->a = NULL;
		stack->b = NULL;
		push_swap(stack, argv, size);
		return (0);
	}
	return (0);
}
