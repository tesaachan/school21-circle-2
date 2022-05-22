/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:42 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 18:13:43 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "model.h"

static float	__model_max_abs(float x, float y)
{
	float	abs_x;
	float	abs_y;

	abs_x = fabs(x);
	abs_y = fabs(y);
	if (abs_x > abs_y)
		return (abs_x);
	return (abs_y);
}

static void	__model_pixel_put(t_model *model, int x, int y, int color)
{
	char	*dst;

	if (x < SIZE_X && y < SIZE_Y && x > 0 && y > 0)
	{
		dst = model->addr + (y * model->line_length
				+ x * (model->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	__model_bresenham(t_model *model, t_dl_utils *dl,
		t_xyz p1, t_xyz p2)
{
	int		i;
	int		color;

	i = 0;
	while ((int)fabs(p2.x - p1.x) > 0 || (int)fabs(p2.y - p1.y) > 0)
	{
		color = __model_gradient(dl->c1, dl->c2, dl->dc, i);
		__model_pixel_put(model, p1.x, p1.y, color);
		p1.x += dl->dx;
		p1.y += dl->dy;
		i++;
	}
}

void	__model_draw_line(t_model *model, t_xyz p1, t_xyz p2)
{
	float		max;
	t_dl_utils	dl;

	p1.z = model->map->field[(int)p1.y][(int)p1.x].value;
	p2.z = model->map->field[(int)p2.y][(int)p2.x].value;
	dl.c1 = model->map->field[(int)p1.y][(int)p1.x].color;
	dl.c2 = model->map->field[(int)p2.y][(int)p2.x].color;
	view_set_display(model->view, &p1, &p2);
	dl.dx = p2.x - p1.x;
	dl.dy = p2.y - p1.y;
	max = __model_max_abs(dl.dx, dl.dy);
	dl.dx /= max;
	dl.dy /= max;
	dl.dc = max / __model_max_abs(dl.dx, dl.dy);
	__model_bresenham(model, &dl, p1, p2);
}
