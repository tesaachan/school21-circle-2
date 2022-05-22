/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:14:00 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 20:28:01 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_BONUS_H
# define VIEW_BONUS_H

# define PI_DIV_FOUR	0.785398
# define PI_DIV_SIX		0.523599

# define ISOMETRIC		1
# define DIMETRIC		2

typedef struct view_s {
	float	zoom;
	int		shift_x;
	int		shift_y;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	int		projection;
	int		height;
	int		width;
}			t_view;

typedef struct xyz_s {
	float	x;
	float	y;
	float	z;
}			t_xyz;

t_view	*view_init(int height, int width);
void	view_move(t_view *view, int keycode);
void	view_rotate(t_view *view, int keycode);
void	view_zoom(t_view *view, int keycode);
void	view_projection(t_view *view, int keycode);
void	view_set_display(t_view *view, t_xyz *p1, t_xyz *p2);
void	__view_set_rotation(t_view *view, t_xyz *p);

#endif
