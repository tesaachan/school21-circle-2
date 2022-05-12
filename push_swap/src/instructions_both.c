/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:33 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:34 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_both(t_stack **a, t_stack **b)
{
	ft_rotate(a, "");
	ft_rotate(b, "");
	ft_print_note("rr\n");
	return ;
}

void	ft_reverse_rotate_both(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, "");
	ft_reverse_rotate(b, "");
	ft_print_note("rrr\n");
	return ;
}
