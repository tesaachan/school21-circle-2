/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akami <akami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:53:15 by akami             #+#    #+#             */
/*   Updated: 2022/03/31 12:57:05 by akami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	size_t			value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_arrays
{
	size_t	length;
	int		*unsorted;
	int		*sorted;
}			t_arrays;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	size_t	a_len;
	size_t	b_len;
}			t_stacks;

typedef struct s_cost
{
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	rr;
	size_t	rrr;
	size_t	total;
}			t_cost;

typedef struct s_optimization
{
	size_t	ra_rrb;
	size_t	rb_rra;
	size_t	ra_rb;
	size_t	rra_rrb;
}			t_optimization;

//libft
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
t_stack	*ft_lstnew(size_t value);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
size_t	ft_lstsize(t_stack *stack);

// puhs_swap
void	ft_print_error(void);
void	ft_print_note(const char *note);
size_t	ft_find_length(char **str);
void	ft_push_into_new(int **new, int **cur, size_t length, size_t flag);

size_t	ft_create_unsort_arr(int argc, char **argv, int **unsort_arr);
void	ft_create_sort_arr(t_arrays *arrays);

//stack_a
t_stack	*ft_create_stack_a(t_arrays *arrays);
size_t	ft_check_sort(t_stack *stack, size_t length);
void	ft_sort_tree(t_stack **stack);
void	ft_final_sort(t_stack **stack, size_t length);

//stack_b
void	ft_create_stack_b(t_stacks *stacks);
void	ft_create_stack_b_from_five_len(t_stacks *stacks);
void	ft_push_from_b_to_a(t_stacks *stacks);

//sort
void	ft_sort(t_stacks *stacks);

//instructions
void	ft_push(t_stack **from, t_stack **to, const char *note);
void	ft_swap(t_stack **stack, const char *note);
void	ft_rotate(t_stack **stack, const char *note);
void	ft_reverse_rotate(t_stack **stack, const char *note);
void	ft_rotate_both(t_stack **a, t_stack **b);
void	ft_reverse_rotate_both(t_stack **a, t_stack **b);

//cost
size_t	ft_create_cost(t_stacks *stacks, t_cost **cost);
void	ft_optimize(t_optimization *opt, t_cost *cost);
void	ft_zeroes(size_t *field_first, size_t *field_second);
void	ft_rr_rrr_handle(size_t	*a, size_t *b, size_t *purpose);

#endif