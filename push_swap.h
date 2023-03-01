#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int		data;
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

# define ASCENDING 0
# define DESCENDING 1
# define OPT 0
# define STACK 1

//Operations
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
//push_swap.c
void	push_swap(char **argv);
t_node	*new_node(int data);
void	add_after(t_node *before, t_node *new_node);
void	del_node(t_node **head, t_node **tail, t_node *p);
//sort.c
void	sort_aaa(t_stack *s);
int		sort(t_stack *s, int size);
int		push(t_stack *s, int len, int operation);
//push_swap_utils.c
void	error_free(int *stack);
int		pusw_strlen(char **argv);
int		pusw_atoi(char *str, int *stack);
int		sort_check(int *stack, int size, int order);
void	duplication_check(int *stack, int size);

t_node	*lst_front(t_node *lst);
t_node	*lst_last(t_node *lst);