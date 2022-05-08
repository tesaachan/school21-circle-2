#include "../include/push_swap.h"

static int	array_check_arg(const char *arg)
{
    int	i;

    i = 0;
    while (arg[i] != '\0')
    {
    	if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '-')
			i++;
		else
			return -1;
	}
	return 0;
}

int	array_set_unsorted(array_t *array, const int argc, const char **args)
{
	int	i;

	array->unsorted = (int *)malloc((argc - 1) * sizeof(int));
	i = 1;
	while (i < argc)
	{
		if (array_check_arg(args[i]) == -1)
			return -1;
		array->unsorted[i - 1] = ft_atoi(args[i]);
		i++;
	}
	array->length = argc - 1;
	return 0;
}
