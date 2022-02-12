/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:43:10 by midfath           #+#    #+#             */
/*   Updated: 2022/02/11 22:38:30 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

static void	ft_check(int ac, char **av)
{
	int		i;
	int		j;
	long	num;

	i = 1;
	while (i < ac)
	{
		num = ft_up_atoi(av[i]);
		if (num == 2147483648 || num == -2147483648)
			ft_error();
		j = i + 1;
		while (j < ac)
		{
			if (num == ft_up_atoi(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

static t_list	*ft_get_num(int ac, char **av)
{
	int		i;
	t_list	*p;
	long	num;

	i = 1;
	p = NULL;
	ft_check(ac, av);
	while (i < ac)
	{
		num = ft_up_atoi(av[i]);
		ft_lstadd_back(&p, st_newnode((void *)&num));
			i++;
	}
	return (p);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (0);
	a = ft_get_num(ac, av);
	b = NULL;
	st_checker(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}
