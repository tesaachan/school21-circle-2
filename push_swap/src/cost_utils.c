/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:29 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:30 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_zeroes(size_t *field_first, size_t *field_second)
{
	*field_first = 0;
	*field_second = 0;
	return ;
}

void	ft_rr_rrr_handle(size_t	*a, size_t *b, size_t *purpose)
{
	if (*a <= *b)
		*purpose = *a;
	else
		*purpose = *b;
	*a -= *purpose;
	*b -= *purpose;
	return ;
}

void	ft_optimize(t_optimization *opt, t_cost *cost)
{
	cost->rr = 0;
	cost->rrr = 0;
	opt->ra_rrb = cost->ra + cost->rrb;
	opt->rb_rra = cost->rb + cost->rra;
	if (cost->ra >= cost->rb)
		opt->ra_rb = cost->ra;
	else
		opt->ra_rb = cost->rb;
	if (cost->rra >= cost->rrb)
		opt->rra_rrb = cost->rra;
	else
		opt->rra_rrb = cost->rrb;
	return ;
}
