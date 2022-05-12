/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsorted_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:49 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:50 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_fill_unsort_arr(const char *str, int **unsorted, size_t l)
{
	char	**elements;
	int		*new_unsorted;
	size_t	inc;
	size_t	iter;

	elements = ft_split(str, ' ');
	if (elements == (void *)0)
		ft_print_error();
	inc = ft_find_length(elements);
	new_unsorted = (int *)malloc(sizeof(int) * (l + inc));
	if (new_unsorted == (void *)0)
		ft_print_error();
	ft_push_into_new(&new_unsorted, unsorted, l, 1);
	iter = 0;
	while (iter < inc)
	{
		new_unsorted[l + iter] = ft_atoi(elements[iter]);
		free(elements[iter]);
		iter++;
	}
	free(elements);
	*unsorted = new_unsorted;
	return (inc);
}

static void	ft_check_err_input(const char *str)
{
	size_t	iter;

	iter = 0;
	while (str[iter] != '\0')
	{
		if ((str[iter] < '0' || str[iter] > '9')
			&& str[iter] != ' ' && str[iter] != '-' && str[iter] != '+')
			ft_print_error();
		iter++;
	}
	return ;
}

size_t	ft_create_unsort_arr(int argc, char **argv, int **unsorted)
{
	size_t	iter;
	size_t	length;

	iter = 1;
	length = 0;
	while ((int)iter < argc)
	{
		ft_check_err_input(argv[iter]);
		length += ft_fill_unsort_arr(argv[iter], unsorted, length);
		iter++;
	}
	return (length);
}
