/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:40 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 20:27:50 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

typedef struct point_s {
	int	value;
	int	color;
}	t_point;

typedef struct map_s
{
	int		height;
	int		width;
	t_point	**field;
}			t_map;

t_map	*map_init(char **lines);
int		__map_hex_atoi(char *str, int pos);

#endif
