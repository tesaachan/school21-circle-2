/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:12:32 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 19:06:05 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "model_bonus.h"

static int	press_cross(t_model *model)
{
	(void)model;
	exit(0);
}

static char	**parser(char *filename)
{
	int		fd;
	char	*buf;
	char	*file_as_line;
	char	*joined;
	char	**parsed;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_msg("failed opening file");
	file_as_line = get_next_line(fd);
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		joined = ft_strjoin(file_as_line, buf);
		free(file_as_line);
		file_as_line = joined;
		free(buf);
		buf = get_next_line(fd);
	}
	parsed = ft_split(file_as_line, '\n');
	free(file_as_line);
	return (parsed);
}

int	main(int argc, char **argv)
{
	char	**lines;
	t_map	*map;
	t_model	*model;

	if (argc != 2)
		ft_error_msg("wrong number of arguments");
	lines = parser(argv[1]);
	map = map_init(lines);
	model = model_init(map);
	model_render(model);
	mlx_hook(model->win, 2, 0, model_handle_keyboard, model);
	mlx_hook(model->win, 17, 0, press_cross, model);
	mlx_loop(model->mlx);
	return (0);
}
