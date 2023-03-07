#include "../../push_swap.h"

void	quick_sort_3(t_stack *stack)
{
	if (stack->size_a == 3)
		sort_aaa(stack);
	else if (stack->size_a == 2)
		if (stack->a->data > stack->a->next->data)
			sa(stack);
	if (stack->size_b == 3)
		sort_bbb(stack);
	else if (stack->size_b == 2)
		sb(stack);
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
t_node* partition(t_stack *stack, t_node* start, t_node* end)
{
	t_node* pivot;
	t_node* i;
	t_node* j;
	int 	pivot_value;

	// if ((stack->size_a >= 1 && stack->size_a <= 3) || (stack->size_b >= 1 && stack->size_b <= 3))
	// 	quick_sort_3(stack);
    pivot = get_median(start, end);
	t_node *temp = stack->a;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	printf("pivot : %d, start : %d\n", pivot->data, start->data);
    swap(&(pivot->data), &(start->data));
	printf("pivot : %d, start : %d\n\n", pivot->data, start->data);
	temp = stack->a;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
    pivot_value = pivot->data;
    i = start->prev;
    j = start;
    while (j->data <= pivot_value)
	{
        // if (j->data <= pivot_value)
		// {
			// if (i == NULL)
			// 	i = start;
			// else
			// 	i = i->next;
			// // if (j->data <= pivot_value)
			// // 	pb(stack);
            // swap(&(i->data), &(j->data));
			pb(stack);
        // }
		printf("j = %d\n", j->data);
		printf("pivot = %d\n", pivot->data);
        j = j->next;
    }
	//printf("stack->b : %d\n", stack->b->data);
    if (i == NULL)
		i = start;
	else
		i = i->next;
    swap(&(i->data), &(end->data));
	// t_node *temp = stack->a;
	// while (temp != NULL)
	// {
	// 	printf("%d ", temp->data);
	// 	temp = temp->next;
	// }
	// printf("\n");
    return (i);
}

void q_sort(t_stack *stack, t_node *start, t_node *end)
{
	t_node *pivot;

    if (end != NULL && start != end && start != end->next) 
	{
        pivot = partition(stack, start, end);
        q_sort(stack, start, pivot->prev);
        q_sort(stack, pivot->next, end);
    }
}

void	quicksort(t_stack *stack)
{
	t_node	*start;
	t_node	*end;

	start = lst_front(stack->a);
	end = lst_last(stack->a);
	q_sort(stack, start, end);
}
