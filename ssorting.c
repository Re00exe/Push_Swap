/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssorting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:45:53 by midfath           #+#    #+#             */
/*   Updated: 2022/02/07 11:45:53 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	st_putitright(t_list **a, t_list **b)
{
	int	max_num;

	max_num = ft_lstsize(*a);
	if (st_isready(*a))
		return (0);
	if (max_num == 2)
		return (st_swap_ab(a, 'a'));
	st_trans(a);
	if (max_num < 6)
	{
		while (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 6)
		{
			st_to_lift(a, lst_min(*a)->content, 'a');
			st_push_ab(b, a, 'b');
		}
		st_smallsorting(a, b);
	}
	else if (max_num >= 6)
		st_radix(a, b, 0);
	return (0);
}

void	st_smallsorting(t_list **a, t_list **b)
{
	if (*(int *)lst_get(*a, 1)->content == *(int *)lst_min(*a)->content && \
		*(int *)lst_get(*a, 2)->content == *(int *)lst_max(*a)->content)
		st_swap_ab(a, 'a');
	if (*(int *)lst_get(*a, 1)->content == *(int *)lst_min(*a)->content && \
		*(int *)lst_get(*a, 0)->content == *(int *)lst_max(*a)->content)
		st_rotate_ab(a, 'a');
	if (*(int *)lst_get(*a, 2)->content == *(int *)lst_min(*a)->content && \
		*(int *)lst_get(*a, 1)->content == *(int *)lst_max(*a)->content)
		st_rev_rotate_ab(a, 'a');
	if (*(int *)lst_get(*a, 0)->content == *(int *)lst_min(*a)->content && \
		*(int *)lst_get(*a, 1)->content == *(int *)lst_max(*a)->content)
	{
		st_swap_ab(a, 'a');
		st_rotate_ab(a, 'a');
	}
	if (*(int *)lst_get(*a, 2)->content == *(int *)lst_min(*a)->content && \
		*(int *)lst_get(*a, 0)->content == *(int *)lst_max(*a)->content)
	{
		st_swap_ab(a, 'a');
		st_rev_rotate_ab(a, 'a');
	}
	while (ft_lstsize(*b))
		st_push_ab(a, b, 'a');
}

static int	stopa(t_list **a, t_list **b)
{
	while (ft_lstsize(*b))
		st_push_ab(a, b, 'a');
	return (0);
}

int	st_radix(t_list **a, t_list **b, int shifter)
{
	int	i;
	int	len;

	if (st_isready(*a))
		return (stopa(a, b));
	i = -1;
	len = ft_lstsize(*a);
	while (++i < len && !st_isready(*a))
	{
		if (!(*(int *)(*a)->content >> shifter & 1))
			st_push_ab(b, a, 'b');
		else
			st_rotate_ab(a, 'a');
	}
	i = -1;
	shifter++;
	len = ft_lstsize(*b);
	while (++i < len)
	{
		if (!(*(int *)(*b)->content >> shifter & 1))
			st_rotate_ab(b, 'b');
		else
			st_push_ab(a, b, 'a');
	}
	return (st_radix(a, b, shifter));
}
