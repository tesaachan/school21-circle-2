/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:47 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:48 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_do_special(t_stacks *stacks, t_cost cost)
{
	while (cost.rr != 0)
	{
		ft_rotate_both(&stacks->a, &stacks->b);
		cost.rr--;
	}
	while (cost.rrr != 0)
	{
		ft_reverse_rotate_both(&stacks->a, &stacks->b);
		cost.rrr--;
	}
	return ;
}

static void	ft_do_general(t_stacks *stacks, t_cost cost)
{
	while (cost.ra != 0)
	{
		ft_rotate(&stacks->a, "ra\n");
		cost.ra--;
	}
	while (cost.rb != 0)
	{
		ft_rotate(&stacks->b, "rb\n");
		cost.rb--;
	}
	while (cost.rra != 0)
	{
		ft_reverse_rotate(&stacks->a, "rra\n");
		cost.rra--;
	}
	while (cost.rrb != 0)
	{
		ft_reverse_rotate(&stacks->b, "rrb\n");
		cost.rrb--;
	}
	return ;
}

void	ft_push_from_b_to_a(t_stacks *stacks)
{
	t_cost	*cost;
	size_t	ind;

	while (stacks->b_len != 0)
	{
		cost = (t_cost *)malloc(sizeof(t_cost) * stacks->b_len);
		ind = ft_create_cost(stacks, &cost);
		ft_do_special(stacks, cost[ind]);
		ft_do_general(stacks, cost[ind]);
		free(cost);
		ft_push(&stacks->b, &stacks->a, "pa\n");
		stacks->a_len++;
		stacks->b_len--;
	}
	return ;
}

void	ft_create_stack_b_from_five_len(t_stacks *stacks)
{
	ft_push(&stacks->a, &stacks->b, "pb\n");
	ft_push(&stacks->a, &stacks->b, "pb\n");
	stacks->a_len -= 2;
	stacks->b_len += 2;
	return ;
}

void	ft_create_stack_b(t_stacks *stacks)
{	
	size_t	a_len_buf;

	a_len_buf = stacks->a_len;
	while (stacks->a_len != 3)
	{
		if (stacks->a->value != 0 && stacks->a->value != (size_t)(a_len_buf / 2)
			&& stacks->a->value != (a_len_buf - 1))
		{
			ft_push(&stacks->a, &stacks->b, "pb\n");
			stacks->b_len++;
			stacks->a_len--;
		}
		else
			ft_rotate(&stacks->a, "ra\n");
	}
	return ;
}
