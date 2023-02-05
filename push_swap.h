#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
} t_stack;