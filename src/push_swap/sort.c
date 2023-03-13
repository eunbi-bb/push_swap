#include "../../push_swap.h"

// void	sort_tmp(int *tmp_stack, int size)
// {
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (tmp_stack[i] > tmp_stack[j])
// 			{
// 				tmp = tmp_stack[i];
// 				tmp_stack[i] = tmp_stack[j];z
// 				tmp_stack[j] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
/*1. 1 3 2
  2. 2 1 3
  3. 2 3 1
  4. 3 1 2
  5. 3 2 1
*/
void	sort_aaa(t_stack *stack)
{
	int	one;
	int	two;
	int	three;

	one = stack->a->data;
	two = stack->a->next->data;
	three = stack->a->next->next->data;
	if (one < two && one < three && two > three)
	{
		sa(stack);
		ra(stack);
	}
	else if (one > two && one < three && two < three)
		sa(stack);
	else if (one < two && one > three && two > three)
		rra(stack);
	else if (one > two && one > three && two < three)
		ra(stack);
	else if (one > two && one > three && two > three)
	{
		sa(stack);
		rra(stack);
	}
}

int	sort(t_stack *stack, int size)
{
	if (sort_check(stack) == 0)
	{
		if (size == 2)
			sa(stack);
		else if (size == 3)
			sort_aaa(stack);
		else
			radix(stack, size);
	}
	return (0);
}

int	push(t_stack *stack, int len, int operation)
{
	if (operation == 0)
		pb(stack);
	else
		pa(stack);
	len--;
	return (len);
}