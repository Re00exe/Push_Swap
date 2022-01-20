
#include "push_swap.h"

int st_ordered(t_list *head)
{
    int x;
    x = head->content;

    if(!head)
        return (0);
    head = head->next;
    while (head)
    {
        if (x > head->content )
            return (0);
        x = head->content;
        head = head->next;
    }
    return (1);
}

int stack_order(t_list **a, t_list **b)
{
    int max;

    max = ft_lstsize(*a) - 1;
    if (st_ordered(*a))
        return (0);
    if (max_value + 1 == 1)
        return (st_swap_ab(a , 'a'));
    st_trans(a);
    while (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 7)
    {
        
    }

}