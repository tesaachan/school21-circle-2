/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hex_atoi_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:30 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 19:06:18 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "map_bonus.h"

int	__map_hex_atoi(char *str, int pos)
{
	int		i;
	int		result;
	int		conv_index;
	char	*base;

	i = pos;
	result = 0;
	base = "0123456789abcdef0123456789ABCDEF";
	while (str[i] != '\0')
	{
		conv_index = 0;
		while (str[i] != base[conv_index])
			conv_index++;
		result = (result * 16) + (conv_index % 16);
		i++;
	}
	return (result);
}
