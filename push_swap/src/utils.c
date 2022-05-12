/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:52 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:53 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_print_note(const char *note)
{
	size_t	iter;

	iter = 0;
	while (note[iter] != '\0')
		write(1, &note[iter++], 1);
	return ;
}

size_t	ft_find_length(char **str)
{
	size_t	iter;

	iter = 0;
	while (str[iter] != (void *)0)
		iter++;
	return (iter);
}

void	ft_push_into_new(int **new, int **cur, size_t length, size_t flag)
{
	size_t	iter;

	iter = 0;
	while (iter < length)
	{
		(*new)[iter] = (*cur)[iter];
		iter++;
	}
	if ((flag == 1) && (length != 0))
		free(*cur);
	return ;
}
