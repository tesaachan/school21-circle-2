/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:57 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 19:06:44 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "view_bonus.h"

static void	__view_proj_isometric(float *x, float *y, int z, float angle)
{
	float	xn;
	float	yn;

	xn = (*x - *y) * cos(angle);
	yn = (*x + *y) * sin(angle) - z;
	*x = xn;
	*y = yn;
}

static void	__view_proj_dimetric(float *x, float *y, int z, float angle)
{
	float	xn;
	float	yn;

	xn = *x - (z * cos(angle));
	yn = *y - (z * sin(angle));
	*x = xn;
	*y = yn;
}

void	view_projection(t_view *view, int keycode)
{
	if (keycode == 6)
		view->projection = 0;
	if (keycode == 7)
		view->projection = ISOMETRIC;
	if (keycode == 8)
		view->projection = DIMETRIC;
}

void	view_set_display(t_view *view, t_xyz *p1, t_xyz *p2)
{
	__view_set_rotation(view, p1);
	__view_set_rotation(view, p2);
	p1->x *= view->zoom;
	p1->y *= view->zoom;
	p1->z *= view->zoom;
	p2->x *= view->zoom;
	p2->y *= view->zoom;
	p2->z *= view->zoom;
	if (view->projection == ISOMETRIC)
	{
		__view_proj_isometric(&p1->x, &p1->y, p1->z, PI_DIV_SIX);
		__view_proj_isometric(&p2->x, &p2->y, p2->z, PI_DIV_SIX);
	}
	else if (view->projection == DIMETRIC)
	{
		__view_proj_dimetric(&p1->x, &p1->y, p1->z, PI_DIV_FOUR);
		__view_proj_dimetric(&p2->x, &p2->y, p2->z, PI_DIV_FOUR);
	}
	p1->x += view->shift_x;
	p1->y += view->shift_y;
	p2->x += view->shift_x;
	p2->y += view->shift_y;
}

t_view	*view_init(int height, int width)
{
	t_view	*this;

	this = (t_view *)malloc(sizeof(t_view));
	if (this == NULL)
		ft_error_msg("failed view initialization");
	this->zoom = 1;
	while (this->zoom * width < SIZE_X && this->zoom * height < SIZE_Y)
		this->zoom++;
	this->zoom /= 10;
	this->shift_x = SIZE_X / 2 - (width * this->zoom / 2);
	this->shift_y = SIZE_Y / 2 - (height * this->zoom / 2);
	this->projection = 1;
	this->rot_x = 0;
	this->rot_y = 0;
	this->rot_z = 0;
	this->height = height;
	this->width = width;
	return (this);
}
