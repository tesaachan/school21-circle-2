/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:22 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:23 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (new == (void *)0)
		return ;
	new->next = *stack;
	*stack = new;
	return ;
}
