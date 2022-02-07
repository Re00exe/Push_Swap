/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:46:34 by midfath           #+#    #+#             */
/*   Updated: 2022/02/07 11:46:34 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*st_newnode(void *num)
{
	t_list	*new;
	void	*content;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	content = malloc(sizeof(int));
	if (!content)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(content, num, sizeof(int));
	new->content = content;
	new->next = NULL;
	return (new);
}

int	st_isready(t_list *head)
{
	void	*x;

	x = NULL;
	if (!head)
		return (0);
	while (head)
	{
		if (x && *(int *)x > *(int *)head->content)
			return (0);
		x = head->content;
		head = head->next;
	}
	return (1);
}

void	st_trans(t_list **stack)
{
	t_list	*tmp;
	int		len;
	int		i;
	int		num;

	i = 0;
	num = 0;
	tmp = NULL;
	len = ft_lstsize(*stack);
	while (i++ < len)
		ft_lstadd_back(&tmp, st_newnode((void *)&num));
	i = 0;
	num = *(int *)lst_max(*stack)->content + 1;
	while (i < len)
	{
		lst_put_at(&tmp, lst_find(*stack, lst_min(*stack)->content) \
		, (void *)&i);
		lst_put_at(stack, lst_find(*stack, lst_min(*stack)->content) \
		, (void *)&num);
		i++;
		num++;
	}
	ft_lstclear(stack, free);
	*stack = tmp;
}

int	st_swap_ss(t_list **a, t_list **b)
{
	st_swap_ab(a, 0);
	st_swap_ab(b, 0);
	write(1, "ss\n", 3);
	return (1);
}

int	st_rotate_rr(t_list **a, t_list **b)
{
	if (!st_rotate_ab(a, 0))
		return (0);
	if (!st_rotate_ab(b, 0))
		return (0);
	write(1, "rr\n", 3);
	return (1);
}
