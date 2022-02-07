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

int	ft_nbrlen(int n, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	st_putitright(t_list **a, t_list **b)
{
	int	max_num;

	max_num = ft_lstsize(*a) - 1;
	if (st_isready(*a))
		return (0);
	if (max_num + 1 == 2)
		return (st_swap_ab(a, 'a'));
	st_trans(a);
	while (ft_lstsize(*a) > 3 && ft_lstsize(*a) < 7)
	{
		st_to_lift(a, lst_min(*a)->content, 'a');
		st_push_ab(b, a, 'b');
	}
	st_smallsorting(a, b);
	if (!st_isready(*a))
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

int	st_radix(t_list **a, t_list **b, int shifter)
{
	int	i;
	int	len;
	int	lim;

	if (st_isready(*a))
	{
		while (ft_lstsize(*b))
			st_push_ab(a, b, 'a');
		return (0);
	}
	i = -1;
	len = ft_lstsize(*a);
	lim = st_checkorder(*a, *b, 'a');
	while (++i < len - lim && !st_isready(*a))
	{
		if (!(*(int *)(*a)->content >> shifter & 1))
			st_push_ab(b, a, 'b');
		else
			st_rotate_ab(a, 'a');
	}
	i = -1;
	len = ft_lstsize(*b);
	while (++i < len - st_checkorder(*a, *b, 'b'))
		st_push_ab(a, b, 'a');
	return (st_radix(a, b, shifter + 1));
}

int	st_checkorder(t_list *a, t_list *b, char c)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (c == 'a' && a)
	{
		if (*(int *)a->content == len)
			count++;
		else
			count = 0;
		len++;
		a = a->next;
	}
	len = ft_lstsize(b) - 1;
	while (c == 'b' && b)
	{
		if (*(int *)b->content == len)
			count++;
		else
			count = 0;
		len--;
		b = b->next;
	}
	return (count);
}
