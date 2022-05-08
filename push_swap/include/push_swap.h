#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //function: write
# include <stdlib.h> //function: malloc free exit
# include "limits.h"
#include "stdio.h"

typedef struct array_s {
	size_t	length;
	int		*sorted;
    int		*unsorted;
}	array_t;

typedef struct stack_s {
	int				val;
    struct stack_s	*next;
}	st_t;

typedef struct stacks_s {
    size_t  a_length;
    size_t  b_length;
    st_t    *a;
    st_t    *b;
}   stacks_t;

/*
 *      push_swap functions
 */
int 	array_set_unsorted(array_t *array, const int argc, const char **args);
int     array_set_sorted(array_t *array);

void	stacks_init_stack_a(stacks_t *stacks, array_t *array);
void    stacks_partial_sort(stacks_t *stacks);
void	stacks_init_stack_b(stacks_t *stacks);

void	error_message(const char *str);

/*
 *      libft functions
 */
int     ft_strlen(const char *str);
int     ft_atoi(const char *str);
void	ft_lstadd_front(st_t **lst, st_t *new);
void	ft_lstadd_back(st_t **lst, st_t *new);
int     ft_lstsize(st_t *lst);
st_t	*ft_lstnew(void *content);

#endif