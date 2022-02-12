/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:18:14 by midfath           #+#    #+#             */
/*   Updated: 2022/02/11 22:36:47 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"
#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	st_checker(t_list **a, t_list **b)
{
	char	*buff;

	buff = get_next_line(0);
	while (buff)
	{
		if (!ft_strcmp(buff, "sa\n") || !ft_strcmp(buff, "sb\n")
			|| !ft_strcmp(buff, "ss\n"))
			swap(a, b, buff);
		else if (!ft_strcmp(buff, "pa\n") || !ft_strcmp(buff, "pb\n"))
			push(a, b, buff);
		else if (!ft_strcmp(buff, "ra\n") || !ft_strcmp(buff, "rb\n")
			|| !ft_strcmp(buff, "rr\n"))
			rotate(a, b, buff);
		else if (!ft_strcmp(buff, "rra\n") || !ft_strcmp(buff, "rrb\n")
			|| !ft_strcmp(buff, "rrr\n"))
			rev_rotate(a, b, buff);
		else
			ft_error();
		free(buff);
		buff = get_next_line(0);
	}
	if (st_isready(*a) && !ft_lstsize(*b))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	ch_swap_ss(t_list **a, t_list **b)
{
	st_swap_ab(a, 0);
	st_swap_ab(b, 0);
	return (1);
}

int	ch_rotate_rr(t_list **a, t_list **b)
{
	if (!st_rotate_ab(a, 0))
		return (0);
	if (!st_rotate_ab(b, 0))
		return (0);
	return (1);
}
