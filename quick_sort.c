#include "push_swap.h"

void	swap(int num1, int num2)
{
	int	tmp;

	tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void	q_sort(int *numbers, int left, int right)
{
	int	pivot;
	int	l_hold;
	int	r_hold;
	int	median;

	l_hold = left;
	r_hold = right;

	median = (left + right) / 2;
	swap(&numbers[left], &numbers[median]);
	while (left < right)
	{
		while ((numbers[right] >=  pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		q_sort(numbers, left, pivot - 1);
	if (right > pivot)
		q_sort(numbers, pivot++, right);
}

void	quicksort(int numbers[], int array_size)
{
	q_sort(numbers, 0, array_size - 1);
}