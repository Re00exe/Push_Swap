/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:04:11 by midfath           #+#    #+#             */
/*   Updated: 2022/02/11 21:59:47 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	swap(t_list **a, t_list **b, char *buff)
{
	if (ft_strcmp(buff, "sa\n") == 0)
		ch_swap_ab(a);
	else if (ft_strcmp(buff, "sb\n") == 0)
		ch_swap_ab(b);
	else if (ft_strcmp(buff, "ss\n") == 0)
		ch_swap_ss(a, b);
}

void	push(t_list **a, t_list **b, char *buff)
{
	if (ft_strcmp(buff, "pa\n") == 0)
		ch_push_ab(a, b);
	else if (ft_strcmp(buff, "pb\n") == 0)
		ch_push_ab(b, a);
}

void	rotate(t_list **a, t_list **b, char *buff)
{
	if (ft_strcmp(buff, "ra\n") == 0)
		ch_rotate_ab(a);
	else if (ft_strcmp(buff, "rb\n") == 0)
		ch_rotate_ab(b);
}

void	rev_rotate(t_list **a, t_list **b, char *buff)
{	
	if (ft_strcmp(buff, "rr\n") == 0)
		ch_rotate_rr(a, b);
	else if (ft_strcmp(buff, "rra\n") == 0)
		ch_rev_rotate_ab(a);
	else if (ft_strcmp(buff, "rrb\n") == 0)
		ch_rev_rotate_ab(b);
	else if (ft_strcmp(buff, "rrr\n") == 0)
		ch_rrotate_rrr(a, b);
}
