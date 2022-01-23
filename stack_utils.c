
#include "push_swap.h"

int is_ordered(t_list *head)
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

void    st_trans(t_list **stack)
{
    t_list  *tmp;
    int     len;
    int     i;
    int     num;

    i = 0;
    num = 0;
    tmp = NULL;
    len = ft_lstsize(*stack)
    while (i++ < len)
        ft_lstadd_back(&tmp, ft_lstnew(num));
    i = 0;
    num = 

}