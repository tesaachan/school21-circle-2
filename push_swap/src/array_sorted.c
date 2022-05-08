#include "../include/push_swap.h"

static void	array_swap(int *x, int *y)
{
	int	tmp;
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}

static size_t	array_partition(int **stock, size_t l, size_t r)
{
	int		m;
	size_t	i;
	size_t	j;
	
	i = l;
	j = r;
	m = (*stock)[(l + r) / 2];
	while (i <= j)
	{
		while ((*stock)[i] < m)
			i++;
		while ((*stock)[j] > m)
			j--;
		if (i >= j)
			break ;
		array_swap(&(*stock)[i], &(*stock)[j]);
		i++;
		j--;
	}
	return j;
}

static void array_quicksort(int **stock, size_t l, size_t r)
{
	size_t	v;

	if (l >= r)
		return ;
	v = array_partition(stock, l, r);
	array_quicksort(stock, l, v);
	array_quicksort(stock, v + 1, r);
}

int	array_set_sorted(array_t *array)
{	
	size_t	i;

	i = 0;
	array->sorted = (int *)malloc(array->length * sizeof(int));
	if (array->sorted == NULL)
		error_message("bad memory allocation");
	while (i < array->length)
	{
		array->sorted[i] = array->unsorted[i];
		i++;
	}
	array_quicksort(&array->sorted, 0, array->length - 1);
	i = 0;
	while (i < array->length - 1)
	{
		if (array->sorted[i] == array->sorted[i + 1])
			return -1;
		i++;
	}
	return 0;
}
