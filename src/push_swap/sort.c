#include "../../push_swap.h"

void	sort_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
/*1. 1 3 2
  2. 2 1 3
  3. 2 3 1
  4. 3 1 2
  5. 3 2 1
*/
void	sort_aaa(t_stack *s)
{
	if (s->a->data < s->a->next->data
		&& s->a->data < s->a->next->next->data
		&& s->a->next->data > s->a->next->next->data)
	{
		sa(s);
		ra(s);
	}
	if (s->a->data > s->a->next->data
		&& s->a->data < s->a->next->next->data
		&& s->a->next->data < s->a->next->next->data)
		sa(s);
	if (s->a->data < s->a->next->data
		&& s->a->data > s->a->next->next->data
		&& s->a->next->data > s->a->next->next->data)
		rra(s);
	if (s->a->data > s->a->next->data
		&& s->a->data > s->a->next->next->data
		&& s->a->next->data < s->a->next->next->data)
		ra(s);
	if (s->a->data > s->a->next->data
		&& s->a->data > s->a->next->next->data
		&& s->a->next->data > s->a->next->next->data)
	{
		sa(s);
		rra(s);
	}
}

int	sort(t_stack *s, int size)
{
	if (sort_check(s, s->size_a, ASCENDING) == 0)
	{
		if (size == 2)
			sa(s);
		else if (size == 3)
			sort_aaa(s);
		else
			quicksort(s);
	}
	return (0);
}

int	push(t_stack *s, int len, int operation)
{
	if (operation == 0)
		pb(s);
	else
		pa(s);
	len--;
	return (len);
}