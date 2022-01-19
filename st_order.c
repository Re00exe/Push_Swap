
#include "push_swap.h"

int st_ordered(t_list *head)
{
    t_list *x;

    if(!head)
        return (0);
    x = NULL;
    while (head)
    {
        if (x && x > head->content )
            return (0);
        x = head->content;
        head = head->next;
    }
    return (1);
}