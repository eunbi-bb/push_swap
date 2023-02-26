#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int		data;
	t_node	*prev;
	t_node	*next;
} t_node;

typedef	struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
} t_stack;

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

//Quick sort
