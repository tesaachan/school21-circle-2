/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:53 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 20:28:29 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_BONUS_H
# define MODEL_BONUS_H

# include "map_bonus.h"
# include "view_bonus.h"

typedef struct model_s {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_view		*view;
}				t_model;

typedef struct draw_line_utils_s {
	float	dx;
	float	dy;
	int		c1;
	int		c2;
	float	dc;
}			t_dl_utils;

t_model	*model_init(t_map *map);
void	model_render(t_model *model);
int		model_handle_keyboard(int keycode, t_model *model);
int		__model_gradient(int c1, int c2, float dc, int i);
void	__model_draw_line(t_model *model, t_xyz p1, t_xyz p2);
void	__model_draw_wireframe(t_model *model);

#endif
