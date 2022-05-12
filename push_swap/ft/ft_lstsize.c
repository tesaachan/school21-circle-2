/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:24 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:25 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_lstsize(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack != (void *)0)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
