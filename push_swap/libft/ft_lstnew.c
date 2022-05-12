/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:54:57 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:54:58 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lstnew(size_t value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == (void *)0)
		ft_print_error();
	new->value = value;
	new->next = (void *)0;
	return (new);
}
