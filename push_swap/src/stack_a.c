/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:44 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:45 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_check_sort(t_stack *stack, size_t length)
{
	t_stack	*tmp;
	int		mono;

	if (length < 3)
		return (1);
	tmp = stack;
	mono = 0;
	while (tmp->next != (void *)0)
	{
		if (tmp->value < tmp->next->value)
			mono++;
		else
			mono--;
		tmp = tmp->next;
	}
	if (mono == (int)(length - 1))
		return (1);
	if (mono == (int)(length - 3) && stack->value > tmp->value)
		return (1);
	return (0);
}

void	ft_sort_tree(t_stack **stack)
{
	size_t	first;
	size_t	second;
	size_t	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first < second && first < third && second > third)
		ft_swap(stack, "sa\n");
	else if (second < first && second < third && third > first)
		ft_swap(stack, "sa\n");
	else if (third < first && third < second && first > second)
		ft_swap(stack, "sa\n");
	return ;
}

static void	ft_loop_rotate(t_stack **stack,
		void (*f)(t_stack **, const char *), size_t iter, const char *note)
{
	while (iter > 0)
	{
		f(stack, note);
		iter--;
	}
	return ;
}

void	ft_final_sort(t_stack **stack, size_t length)
{
	t_stack	*tmp;
	size_t	iter;

	tmp = *stack;
	iter = 0;
	while (tmp->value != 0)
	{
		iter++;
		tmp = tmp->next;
	}
	if (iter > length - iter)
		ft_loop_rotate(stack, &ft_reverse_rotate, length - iter, "rra\n");
	else
		ft_loop_rotate(stack, &ft_rotate, iter, "ra\n");
	return ;
}

t_stack	*ft_create_stack_a(t_arrays *arrays)
{
	t_stack	*stack_a;
	size_t	i;
	size_t	j;

	i = 0;
	stack_a = (void *)0;
	while (i < arrays->length)
	{
		j = 0;
		while (arrays->unsorted[i] != arrays->sorted[j])
			j++;
		ft_lstadd_back(&stack_a, ft_lstnew(j));
		i++;
	}
	free(arrays->unsorted);
	return (stack_a);
}
