#include "../include/push_swap.h"

int     stacks_is_a_sorted(stacks_t *stacks)
{
    st_t	*tmp;
	long	i;

	if (stacks->a_length < 3)
		return 1;
	i = 0;
	tmp = stacks->a;
	while (tmp->next != NULL)
	{
		if (tmp->val < tmp->next->val)
			i++;
		else
			i--;
		tmp = tmp->next;
	}
	if ((i == (long)(stacks->a_length - 1)) ||
        (i == (long)(stacks->a_length - 3) && (stacks->a)->val > tmp->val))
		return 1;
	return 0;
}

void	stacks_init_stack_a(stacks_t *stacks, array_t *array)
{
    size_t	i;
    size_t	j;

    i = 0;
    stacks->a = NULL;
    while (i < array->length)
    {
        j = 0;
        while (array->unsorted[i] != array->sorted[j])
            j++;
        ft_lstadd_back(&stacks->a, ft_lstnew(j));
        i++;
    }
    stacks->a_length = array->length;
    free(array->unsorted);
}
