/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:36 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:53:37 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack **from, t_stack **to, const char *note)
{
	t_stack	*tmp;

	if ((*from) == (void *)0)
		return ;
	ft_lstadd_front(to, ft_lstnew((*from)->value));
	tmp = (*from)->next;
	free(*from);
	*from = tmp;
	ft_print_note(note);
	return ;
}

void	ft_swap(t_stack **stack, const char *note)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_lstadd_front(stack, ft_lstnew(tmp->value));
	free(tmp);
	ft_print_note(note);
	return ;
}

void	ft_rotate(t_stack **stack, const char *note)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	ft_lstadd_back(stack, ft_lstnew((*stack)->value));
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	ft_print_note(note);
	return ;
}

void	ft_reverse_rotate(t_stack **stack, const char *note)
{
	t_stack	*iter;

	if (ft_lstsize(*stack) < 2)
		return ;
	iter = *stack;
	while (iter->next->next != (void *)0)
		iter = iter->next;
	ft_lstadd_front(stack, ft_lstnew(iter->next->value));
	free(iter->next);
	iter->next = (void *)0;
	ft_print_note(note);
	return ;
}
