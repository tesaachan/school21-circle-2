#include "../include/push_swap.h"

static void    stacks_sort_rest_a(stacks_t *stacks)
{
    st_t *fst;
    st_t *scn;
    st_t *thr;

    fst = stacks->a;
    scn = fst->next;
    thr = scn->next;

    if (scn->val < fst->val)
        // st_swap(fst->val, scn->val);
    if (thr->val < fst->val)
    {
        // st_swap(scn->val, thr->val);
        // st_swap(fst->val, scn->val);
    }
    else if (thr->val < scn->scn)
        // st_swap(scn->val, thr->val);
}

void    stacks_partial_sort(stacks_t *stacks)
{
    stacks_init_stack_b(stacks);
    stacks_sort_rest_a(stacks);
}
