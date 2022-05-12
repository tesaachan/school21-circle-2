/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:26 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:27 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	size_t	ft_b(char const *s, char *c)
{
	int		flag;
	size_t	iter;
	size_t	buf_size;

	iter = 0;
	buf_size = 0;
	while (s[iter] != '\0')
	{
		flag = 0;
		while (s[iter] == *c && s[iter] != '\0')
			iter++;
		while (s[iter] != *c && s[iter] != '\0')
		{
			flag = 1;
			iter++;
		}
		if (flag == 1)
			buf_size++;
	}
	return (buf_size);
}

static	size_t	ft_s(char const *s, char *c)
{
	size_t	iter;

	iter = 0;
	while (s[iter] != '\0' && s[iter] != *c)
		iter++;
	return (iter);
}

static	char	**ft_clean(char **buf)
{
	size_t	iter;

	iter = 0;
	while (buf[iter] != (void *)0)
		free(buf[iter++]);
	free(buf);
	return ((void *)0);
}

static	char	*ft_fill(char *buf, char const *s, char *c)
{
	size_t	iter;

	iter = 0;
	while (s[iter] != '\0' && s[iter] != *c)
	{
		buf[iter] = s[iter];
		iter++;
	}
	buf[iter] = '\0';
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	char	**buf;
	size_t	iter;
	size_t	o;

	if (s == (void *)0)
		return ((void *)0);
	iter = 0;
	o = 0;
	buf = (char **)malloc(sizeof(char *) * (ft_b(s, &c) + 1));
	if (buf == (void *)0)
		return ((void *)0);
	while (s[iter] != '\0')
	{
		if (s[iter] != '\0' && s[iter] != c)
		{	
			buf[o++] = (char *)malloc(sizeof(char) * (ft_s(&s[iter], &c) + 1));
			if (buf[o - 1] == (void *)0)
				return (ft_clean(buf));
			buf[o - 1] = ft_fill(buf[o - 1], &s[iter], &c);
			iter += ft_s(&s[iter], &c) - 1;
		}
		iter++;
	}
	buf[o] = (void *)0;
	return (buf);
}
