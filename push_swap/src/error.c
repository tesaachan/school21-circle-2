#include "../include/push_swap.h"

void	error_message(const char *str)
{
    write(2, "Error: ", 7);
	write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    exit(1);
}
