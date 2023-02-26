#include "push_swap.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 1)
	{
		ft_printf("Too less arguments. It should be more than 1.");
		break ;
	}
	else
	{
		while (argv[i])
		{
			if (ft_atoi(argv[i]) == 0 || ft_isalpha(argv[i]) != 0)
			{
				ft_printf("Error. Invalid argument.");
				break;
			}
			i++;
		}
		argv++; //skipping space at the first.
		ft_split(argv, ' '); //remove all spaces. 
		push_swap(argv);
	}
	return (0);
}