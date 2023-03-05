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

int	pusw_atoi(char *str, t_node *stack)
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

int	sort_check(t_node *stack, int size, int order)
{
	t_node	*tmp;

	tmp = stack->a;
	if (order == ASCENDING)
	{
		while(tmp->next != NULL)
		{
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		ft_printf ("The arguments are in ascending order.\n");
		return (1);
	}
	else
	{
		while (tmp->next != NULL)
		{
			if (tmp->data < tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
}

void	duplication_check(t_node *stack)
{
	t_node *current;
	t_node *runner;

	current = stack;
    while (current != NULL)
	{
        runner = current->next;
        while (runner != NULL)
		{
            if (runner->data == current->data)
			{
				error_free(stack);
				return;
            }
            runner = runner->next;
        }
        current = current->next;
    }
}