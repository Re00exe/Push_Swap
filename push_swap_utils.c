/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:44:03 by midfath           #+#    #+#             */
/*   Updated: 2021/12/20 15:41:05 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_swap_ab(t_list **head, char c)
{
	t_list	*node;
	void	*swp;

	node = *head;
	if (ft_lstsize(*head) > 1)
	{
		swp = node->content;
		node->content = node->next->content;
		node->next->content = swp;
		if (c == 'a')
			write(1, "sa\n", 3);
		if (c == 'b')
			write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	st_push_ab(t_list **src, t_list **dst, char c)
{
	void	*node;

	if (ft_lstsize(*dst))
	{
		node = st_pop_out(dst);
		st_new_push(src, node);
		free(node);
		if (c == 'a')
			write(1, "pa\n", 3);
		if (c == 'b')
			write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}

int	st_rotate_ab(t_list **head, char c)
{
	void	*node;

	if (ft_lstsize(*head) > 1)
	{
			node = st_pop_out(head);
		ft_lstadd_back(head, ft_lstnew(node));
		if (c == 'a')
			write(1, "ra\n", 3);
		if (c == 'b')
			write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	st_rev_rotate_ab(t_list **node, char c)
{
	void	*content;
	t_list	*tmp;
	t_list	*end;

	if (ft_lstsize(*node) > 1)
	{
		end = lst_get(*node, ft_lstsize(*node) - 1);
		tmp = lst_get(*node, ft_lstsize(*node) - 2);
		content = end->content;
		st_new_push(node, content);
		ft_lstdelone(end, free);
		tmp->next = NULL;
		if (c == 'a')
			write(1, "rra\n", 4);
		if (c == 'b')
			write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	st_rrotate_rrr(t_list **a, t_list **b)
{
	if (!st_rev_rotate_ab(a, 0))
		return (0);
	if (!st_rev_rotate_ab(b, 0))
		return (0);
	write(1, "rrr\n", 4);
	return (1);
}
