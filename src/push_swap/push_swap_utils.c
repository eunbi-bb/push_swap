#include "../../push_swap.h"

void	error_free(t_node *stack)
{
	ft_printf("Error\n");
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
	if (i == 0)
	{
		ft_printf("Error\n");
		exit(1);
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
		if (str[i] < '0' || str[i] > '9' || !str[i])
			error_free(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > INT32_MAX && sign == -1) || (num > (INT32_MAX - 1) && sign == 1))
		error_free(stack);
	return (sign *num);
}
/*Check out if the stack is sorted.
return 1 if it is sorted. Otherwise 0.*/
int	sort_check(t_stack *stack)
{
	t_node	*tmp;
	int		prev_value;

	if (!stack)
		return(1);
	tmp = stack->a;
	prev_value = tmp->data;
	while (tmp)
	{
		if (tmp->data < prev_value)
			return (0);
		prev_value = tmp->data;
		tmp = tmp->next;
	}
	return(1);
}

void	duplication_check(t_node *stack)
{
	t_node *current;
	t_node *runner;

	if (stack == NULL)
		return ;
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
