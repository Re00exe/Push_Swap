/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:18:14 by midfath           #+#    #+#             */
/*   Updated: 2022/02/08 10:27:56 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	st_checker(t_list **a, t_list **b)
{
	int		max_num;
	char	*buff;

	max_num = ft_lstsize(*a) - 1;
	if (st_isready(*a))
		write(1 , "OK\n", 3);
	buff = get_next_line(0);
	st_rules_check(buff);
}

int	st_rules_check(char *buff)
{
	int	i;

	while (*buff)
	{
		
	}	
}
