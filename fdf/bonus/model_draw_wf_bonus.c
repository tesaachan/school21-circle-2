/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_draw_wf_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:45 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 19:06:35 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "model_bonus.h"

static void	__model_draw_x(t_model *model, t_xyz p1, t_xyz p2)
{
	p2.x = p1.x + 1;
	p2.y = p1.y;
	__model_draw_line(model, p1, p2);
}

static void	__model_draw_y(t_model *model, t_xyz p1, t_xyz p2)
{
	p2.x = p1.x;
	p2.y = p1.y + 1;
	__model_draw_line(model, p1, p2);
}

void	__model_draw_wireframe(t_model *model)
{
	t_xyz	p1;
	t_xyz	p2;

	p2.x = 0;
	p2.y = 0;
	p1.y = 0;
	while (p1.y < model->map->height)
	{
		p1.x = 0;
		while (p1.x < model->map->width)
		{
			if (p1.x < model->map->width - 1)
				__model_draw_x(model, p1, p2);
			if (p1.y < model->map->height - 1)
				__model_draw_y(model, p1, p2);
			p1.x++;
		}
		p1.y++;
	}
}
