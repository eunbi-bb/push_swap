#include "../../push_swap.h"

void	error_free(int *stack)
{
	ft_printf("ERROR\n");
	free(stack);
	exit (1);
}
/*return the number of arguments*/
int	pusw_strlen(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

int	pusw_atoi(char *str, int *stack)
{
	unsigned int	i;
	long long		num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
				error_free(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > INT32_MAX && sign == -1) || (num > (INT32_MAX - 1) && sign == 1))
		error_free(stack);
	return (sign *num);
}

int	sort_check(int *stack, int size, int order)
{
	int	i;

	i = 1;
	if (order == ASCENDING)
	{
		while(i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		ft_printf ("The arguments are in ascending order.\n");
		return (1);
	}
	else
	{
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	duplication_check(int *stack, int size)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				error_free(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}
