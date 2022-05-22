/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:13:48 by akami             #+#    #+#             */
/*   Updated: 2022/05/21 18:13:49 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "model.h"

static int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

static int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	__model_gradient(int c1, int c2, float dc, int i)
{
	int		trgb;
	float	dt;
	float	dr;
	float	dg;
	float	db;

	dt = get_t(c2) - get_t(c1);
	dr = get_r(c2) - get_r(c1);
	dg = get_g(c2) - get_g(c1);
	db = get_b(c2) - get_b(c1);
	trgb = (int)(get_t(c1) + (dt / dc) * i) << 24
		| (int)(get_r(c1) + (dr / dc) * i) << 16
		| (int)(get_g(c1) + (dg / dc) * i) << 8
		| (int)(get_b(c1) + (db / dc) * i);
	return (trgb);
}
