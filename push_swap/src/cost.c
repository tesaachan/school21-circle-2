/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:31 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:32 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	ft_find_min(t_stack *a)
{
	t_stack	*tmp;
	size_t	iter;
	size_t	min_val;
	size_t	min_ind;

	tmp = a;
	iter = 0;
	min_val = __INT32_MAX__;
	min_ind = 0;
	while (tmp != (void *)0)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_ind = iter;
		}
		iter++;
		tmp = tmp->next;
	}
	return (min_ind);
}

static size_t	ft_find_position(size_t	val, t_stack *a)
{
	t_stack	*tmp;
	size_t	flag;
	size_t	iter;

	tmp = a;
	flag = 0;
	iter = 0;
	while (tmp->next != (void *)0)
	{
		iter++;
		if (tmp->value < val && tmp->next->value > val)
		{
			flag = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (flag == 0)
	{
		if (tmp->value < val && a->value > val)
			return (0);
		else
			return (ft_find_min(a));
	}
	return (iter);
}

static void	ft_choose_best(t_cost *cost)
{
	t_optimization	opt;

	ft_optimize(&opt, cost);
	if (opt.ra_rrb <= opt.rb_rra && opt.ra_rrb <= opt.ra_rb
		&& opt.ra_rrb <= opt.rra_rrb)
		ft_zeroes(&cost->rb, &cost->rra);
	else if (opt.rb_rra <= opt.ra_rrb && opt.rb_rra <= opt.ra_rb
		&& opt.rb_rra <= opt.rra_rrb)
		ft_zeroes(&cost->ra, &cost->rrb);
	else if (opt.ra_rb <= opt.ra_rrb && opt.ra_rb <= opt.rb_rra
		&& opt.ra_rb <= opt.rra_rrb)
	{
		ft_zeroes(&cost->rra, &cost->rrb);
		ft_rr_rrr_handle(&cost->ra, &cost->rb, &cost->rr);
	}
	else
	{
		ft_zeroes(&cost->ra, &cost->rb);
		ft_rr_rrr_handle(&cost->rra, &cost->rrb, &cost->rrr);
	}
	cost->total = cost->ra + cost->rb + cost->rra + cost->rrb
		+ cost->rr + cost->rrr;
	return ;
}

static size_t	ft_find_best(t_cost *cost, size_t len)
{
	size_t	best_score;
	size_t	best_ind;
	size_t	iter;

	best_score = __INT32_MAX__;
	best_ind = 0;
	iter = 0;
	while (iter < len)
	{
		if (cost[iter].total < best_score)
		{
			best_score = cost[iter].total;
			best_ind = iter;
		}
		iter++;
	}
	return (best_ind);
}

size_t	ft_create_cost(t_stacks *stacks, t_cost **cost)
{
	t_stack	*tmp;
	size_t	iter;
	size_t	position;

	tmp = stacks->b;
	iter = 0;
	while (tmp != (void *)0)
	{
		(*cost)[iter].rb = iter % stacks->b_len;
		(*cost)[iter].rrb = (stacks->b_len - iter) % stacks->b_len;
		position = ft_find_position(tmp->value, stacks->a);
		(*cost)[iter].ra = position % stacks->a_len;
		(*cost)[iter].rra = (stacks->a_len - position) % stacks->a_len;
		ft_choose_best(&(*cost)[iter]);
		iter++;
		tmp = tmp->next;
	}
	return (ft_find_best(*cost, stacks->b_len));
}
