/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:13 by georgy            #+#    #+#             */
/*   Updated: 2022/03/29 19:50:07 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

st_t	*ft_lstnew(void *content)
{
	st_t	*temp;

	temp = (st_t *)malloc(sizeof(st_t));
	if (temp == NULL)
		return (NULL);
	temp->val = content;
	temp->next = NULL;
	return (temp);
}
