/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 14:24:30 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/21 18:22:38 by eucho         ########   odam.nl         */
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
			stack->a = new_node(tmp, -1);
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
	free_stack(stack);
}

void	free_argv(char **argv)
{
	int		i;

	i = 0;
	while (argv && argv[i])
	{	
		free(argv[i]);
		i++;
	}
	if (argv)
		free(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**tmp;
	int		size;

	tmp = argv;
	if (argc > 1)
	{
		tmp++;
		if (argc == 2)
		{
			tmp = ft_split(*tmp, ' ');
		}
		size = pusw_strlen(tmp);
		stack = malloc(sizeof(t_stack));
		if (!stack)
			return (0);
		stack->a = NULL;
		stack->b = NULL;
		push_swap(stack, tmp, size);
		if (argc == 2)
			free_argv(tmp);
	}
	return (0);
}
