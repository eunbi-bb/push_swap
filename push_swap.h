#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct s_node
{
	int				data;
	unsigned int	index;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef	struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
} t_stack;
//Operations
//swap.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
//push.c
void	pa(t_stack *stack);
void	pb(t_stack *stack);
//rotate.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
//reverse rotate.c
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
//push_swap.c
void	push_swap(char **argv);
t_node	*lst_front(t_node *lst);
t_node	*lst_last(t_node *lst);
//push_swap_utils.c
void	error_free(t_node *stack);
int		pusw_strlen(char **argv);
int		pusw_atoi(char *str, t_node *stack);
void	duplication_check(t_node *stack);
//node_utils.c
t_node	*new_node(int data, int index);
void	add_before(t_node *current, t_node *new_node);
void	add_after(t_node *before, t_node *new_node);
void	del_node(t_node **head, t_node **tail, t_node *p);
//sort.c
void	sort_aaa(t_stack *stack);
void	sort_by_min(t_stack *stack);
void	sort_by_max(t_stack *stack);
void	find_fastest(t_stack *stack);
void	sort(t_stack *stack);
//sort_utils.c
t_node			*get_min(t_node *stack, long lower_limit);
unsigned int	get_max(t_node *stack);
void			put_index(t_stack *stack);
int				sort_check(t_stack *stack);
//radix.c
void	radix(t_stack *stack, int size);
#endif