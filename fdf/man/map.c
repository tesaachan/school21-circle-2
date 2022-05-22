/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:33 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 18:13:34 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map.h"

static int	__map_find_color_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			if (str[i + 1] != '0' || str[i + 2] != 'x')
				ft_error_msg("wrong color passed, must be hexademical");
			return (i + 3);
		}
		i++;
	}
	return (-1);
}

static void	__map_fill_points(t_map *map, int pos, char **line)
{
	int	i;
	int	color_pos;

	i = 0;
	while (line[i] != NULL)
	{
		map->field[pos][i].value = ft_atoi(line[i]);
		color_pos = __map_find_color_pos(line[i]);
		if (color_pos != -1)
			map->field[pos][i].color = __map_hex_atoi(line[i], color_pos);
		else
			map->field[pos][i].color = DEF_COLOR;
		free(line[i]);
		i++;
	}
}

static void	__map_fill_field(t_map *map, char **lines)
{
	int		i;
	char	**line;

	i = 0;
	while (lines[i] != NULL)
	{
		line = ft_split(lines[i], ' ');
		map->field[i] = (t_point *)malloc(map->width * sizeof(t_point));
		if (map->field == NULL)
			ft_error_msg("failed map_fill_field");
		__map_fill_points(map, i, line);
		free(line);
		free(lines[i]);
		i++;
	}
}

static t_point	**__map_create_field(int height)
{
	t_point	**field;

	field = (t_point **)malloc(height * sizeof(t_point *));
	if (field == NULL)
		ft_error_msg("failed field creation");
	return (field);
}

t_map	*map_init(char **lines)
{
	int		i;
	int		j;
	char	**line_for_width;
	t_map	*this;

	this = (t_map *)malloc(sizeof(t_map));
	if (this == NULL)
		ft_error_msg("failed map initialization");
	i = 0;
	while (lines[i] != NULL)
		i++;
	line_for_width = ft_split(lines[0], ' ');
	j = 0;
	while (line_for_width[j] != NULL)
	{
		free(line_for_width[j]);
		j++;
	}
	free(line_for_width);
	this->height = i;
	this->width = j;
	this->field = __map_create_field(this->height);
	__map_fill_field(this, lines);
	free(lines);
	return (this);
}
