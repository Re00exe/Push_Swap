/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rules_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:12:26 by midfath           #+#    #+#             */
/*   Updated: 2022/02/10 13:12:26 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ch_swap_ab(t_list **head)
{
	t_list	*node;
	void	*swp;

	node = *head;
	if (ft_lstsize(*head) > 1)
	{
		swp = node->content;
		node->content = node->next->content;
		node->next->content = swp;
	}
	return (0);
}

int	ch_push_ab(t_list **a, t_list **b)
{
	void	*node;

	if (ft_lstsize(*b))
	{
		node = st_pop_out(b);
		st_new_push(a, node);
		if (node)
			free(node);
		return (1);
	}
	return (0);
}

int	ch_rotate_ab(t_list **head)
{
	void	*node;

	if (ft_lstsize(*head) > 1)
	{
		node = st_pop_out(head);
		ft_lstadd_back(head, ft_lstnew(node));
		return (1);
	}
	return (0);
}

int	ch_rev_rotate_ab(t_list **node)
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
		return (1);
	}
	return (0);
}

int	ch_rrotate_rrr(t_list **a, t_list **b)
{
	if (!st_rev_rotate_ab(a, 0))
		return (0);
	if (!st_rev_rotate_ab(b, 0))
		return (0);
	return (1);
}
