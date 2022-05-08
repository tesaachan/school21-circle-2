/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:40:14 by akami             #+#    #+#             */
/*   Updated: 2022/03/14 17:40:15 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_strdup(const char *s1)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (*s1)
	{
		s2[i++] = *s1++;
	}
	s2[i] = '\0';
	return ((char *)s2);
}
