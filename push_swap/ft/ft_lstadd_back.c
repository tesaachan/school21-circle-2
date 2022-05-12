/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:20 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:21 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*iter;

	if (new == (void *)0)
		return ;
	if (*stack)
	{
		iter = *stack;
		while (iter->next != (void *)0)
			iter = iter->next;
		iter->next = new;
	}
	else
		*stack = new;
	return ;
}
