#include "../include/push_swap.h"

int main(const int argc, const char **argv)
{
    array_t     array;
    stacks_t    stacks;

    if (array_set_unsorted(&array, argc, argv) == -1)
        error_message("wrong input");
    if (array_set_sorted(&array) == -1)
        error_message("contains duplicates");
    stacks_init_stack_a(&stacks, &array);
    if (stacks_is_a_sorted(&stacks) == 0)
        stacks_partial_sort(&stacks);
    stacks_final_sort(&stacks);
    free(array.sorted);
    stacks_free(&stacks);
    return (0);
}
