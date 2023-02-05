#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_printf("Too less arguments. It should be more than 1.");
		break ;
	}
	else
	{
		if (argv != number)
			ft_printf("Error");
		argv++; //skipping space at the first.
		ft_split(argv, ' '); //remove all spaces. 
		push_swap(argv);
	}
	return (0);
}