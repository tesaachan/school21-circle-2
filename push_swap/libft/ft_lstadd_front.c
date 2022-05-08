/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:01 by georgy            #+#    #+#             */
/*   Updated: 2022/03/29 19:49:49 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_front(st_t **lst, st_t *new)
{
	st_t	*temp;

	if (*lst)
	{
		temp = new;
		temp->next = *lst;
		*lst = temp;
	}
	else
	{
		*lst = new;
	}
}
