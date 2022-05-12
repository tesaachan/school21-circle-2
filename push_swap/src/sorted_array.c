/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:42 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:43 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap_values(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

static void	ft_insetion_sort(int **arr, size_t length)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < (int)length)
	{
		j = i - 1;
		key = (*arr)[i];
		while (j >= 0)
		{
			if ((*arr)[j] < key)
				break ;
			ft_swap_values(&(*arr)[j], &(*arr)[j + 1]);
			j--;
		}
		i++;
	}
	return ;
}

static void	ft_check_dup(int *arr, size_t length)
{
	size_t	iter;

	iter = 0;
	while (iter < length - 1)
	{
		if (arr[iter] == arr[iter + 1])
			ft_print_error();
		iter++;
	}
	return ;
}

void	ft_create_sort_arr(t_arrays *arrays)
{
	arrays->sorted = (int *)malloc(sizeof(int) * arrays->length);
	if (arrays->sorted == (void *)0)
		ft_print_error();
	ft_push_into_new(&arrays->sorted, &arrays->unsorted, arrays->length, 0);
	ft_insetion_sort(&arrays->sorted, arrays->length);
	ft_check_dup(arrays->sorted, arrays->length);
	return ;
}
