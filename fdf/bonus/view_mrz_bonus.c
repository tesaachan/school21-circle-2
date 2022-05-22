/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_mrz_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:55 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 19:06:52 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "model_bonus.h"

void	view_move(t_view *view, int keycode)
{
	if (keycode == 13)
		view->shift_y -= 10;
	else if (keycode == 1)
		view->shift_y += 10;
	else if (keycode == 0)
		view->shift_x -= 10;
	else if (keycode == 2)
		view->shift_x += 10;
}

void	view_rotate(t_view *view, int keycode)
{
	if (keycode == 32)
		view->rot_z -= 0.05;
	else if (keycode == 31)
		view->rot_z += 0.05;
	else if (keycode == 34)
		view->rot_y += 0.05;
	else if (keycode == 40)
		view->rot_y -= 0.05;
	else if (keycode == 37)
		view->rot_x += 0.05;
	else if (keycode == 38)
		view->rot_x -= 0.05;
}

void	view_zoom(t_view *view, int keycode)
{
	float	dz;
	int		max_side;

	dz = 0.5;
	max_side = view->height;
	if (view->width > max_side)
		max_side = view->width;
	if (keycode == 24 && view->zoom + dz <= (10 * exp(1)) / log(max_side) - 1)
		view->zoom += dz;
	else if (keycode == 27 && view->zoom - dz >= 1)
		view->zoom -= dz;
}

void	__view_set_rotation(t_view *view, t_xyz *p)
{
	float	h;
	float	w;
	t_xyz	pn;

	h = (view->height * view->zoom) / 2;
	w = (view->width * view->zoom) / 2;
	pn.x = p->x * view->zoom;
	pn.y = p->y * view->zoom;
	pn.z = p->z * view->zoom;
	p->y = (pn.y - w) * cos(view->rot_x) - pn.z * sin(view->rot_x);
	p->z = (pn.y - w) * sin(view->rot_x) + pn.z * cos(view->rot_x);
	pn.y = p->y;
	pn.z = p->z;
	p->x = (pn.x - h) * cos(view->rot_y) - pn.z * sin(view->rot_y);
	p->z = (pn.x - h) * sin(view->rot_y) + pn.z * cos(view->rot_y);
	pn.x = p->x;
	pn.z = p->z;
	p->x = pn.x * cos(view->rot_z) - pn.y * sin(view->rot_z);
	p->y = pn.x * sin(view->rot_z) + pn.y * cos(view->rot_z);
}
