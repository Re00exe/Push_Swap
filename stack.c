
#include "push_swap.h"

t_list	*lst_max(t_list *head)
{
	t_list	*max;

	max = NULL;
	while (head)
	{
		if (!max || max->content < head->content )
			max = head;
		head = head->next;
	}
	return (max);
}