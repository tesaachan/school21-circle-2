/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:51 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 19:06:22 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "model_bonus.h"

static void	__model_show_menu(t_model *model, int keycode)
{
	static int	flag = 0;

	if (keycode == 46)
		flag++;
	if (flag % 2)
	{
		mlx_string_put(model->mlx, model->win, 100, 100, DEF_COLOR,
			"Manual to akami's fdf:");
		mlx_string_put(model->mlx, model->win, 100, 130, DEF_COLOR,
			"WASD - move");
		mlx_string_put(model->mlx, model->win, 100, 150, DEF_COLOR,
			"UIOJKL - rotate");
		mlx_string_put(model->mlx, model->win, 100, 170, DEF_COLOR,
			"ZXC - projections");
		mlx_string_put(model->mlx, model->win, 100, 190, DEF_COLOR,
			"-+ - zoom");
		mlx_string_put(model->mlx, model->win, 100, 210, DEF_COLOR,
			"R - reload");
	}
}

int	model_handle_keyboard(int keycode, t_model *model)
{
	if (keycode == 53)
		exit(0);
	else if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		view_move(model->view, keycode);
	else if (keycode == 24 || keycode == 27)
		view_zoom(model->view, keycode);
	else if (keycode == 31 || keycode == 32 || keycode == 34
		|| keycode == 37 || keycode == 38 || keycode == 40)
		view_rotate(model->view, keycode);
	else if (keycode >= 6 && keycode <= 8)
		view_projection(model->view, keycode);
	else if (keycode == 15)
	{	
		free(model->view);
		model->view = view_init(model->map->height, model->map->width);
	}
	mlx_clear_window(model->mlx, model->win);
	model_render(model);
	__model_show_menu(model, keycode);
	return (0);
}

void	model_render(t_model *model)
{
	model->img = mlx_new_image(model->mlx, SIZE_X, SIZE_Y);
	model->addr = mlx_get_data_addr(model->img, &model->bits_per_pixel,
			&model->line_length, &model->endian);
	__model_draw_wireframe(model);
	mlx_put_image_to_window(model->mlx, model->win, model->img, 0, 0);
}

t_model	*model_init(t_map *map)
{
	t_model	*this;

	this = (t_model *)malloc(sizeof(t_model));
	if (this == NULL)
		ft_error_msg("failed model initialization");
	this->map = map;
	this->mlx = mlx_init();
	this->win = mlx_new_window(this->mlx, SIZE_X, SIZE_Y, "FDF");
	this->view = view_init(map->height, map->width);
	return (this);
}
