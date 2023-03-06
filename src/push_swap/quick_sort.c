#include "../../push_swap.h"

void	quick_sort_3(t_stack *stack)
{
	if (stack->size_a == 3)
		sort_aaa(stack);
}

void	swap(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

t_node* get_median(t_node *start, t_node *end)
{
	t_node *mid;
	t_node *n;
	int i;
	int j;

	mid = start;
    n = start;
    i = 0;
    while (n != end)
	{
        i++;
        n = n->next;
    }
    i = i / 2;
    j = 0;
    while (j < i)
	{
        mid = mid->next;
        j++;
    }
    return (mid);
}
/* Considers last element as pivot, places the
pivot element at its correct position in sorted array,
and places all smaller (smaller than pivot) to left
of pivot and all greater elements to right of pivot */
t_node* partition(t_node* start, t_node* end)
{
	t_node* pivot;
	t_node* i;
	t_node* j;
	int 	pivot_value;

    pivot_value = end->data;
    i = start->prev;
    j = start;
    pivot = get_median(start, end);
    swap(&(pivot->data), &(end->data));
    while (j != end)
	{
        if (j->data <= pivot_value)
		{
			if (i == NULL)
				i = start;
			else
				i = i->next;
            swap(&(i->data), &(j->data));
        }
        j = j->next;
    }
    if (i == NULL)
		i = start;
	else
		i = i->next;
    swap(&(i->data), &(end->data));
    return (i);
}

void q_sort(t_node* start, t_node* end) 
{
	t_node *pivot;

    if (end != NULL && start != end && start != end->next) 
	{
        pivot = partition(start, end);
        q_sort(start, pivot->prev);
        q_sort(pivot->next, end);
    }
}

void	quicksort(t_stack *s)
{
	t_node	*start;
	t_node	*end;

	start = lst_front(s->a);
	end = lst_last(s->a);
	q_sort(start, end);
}
