/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:44:03 by midfath           #+#    #+#             */
/*   Updated: 2021/12/19 11:13:34 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	n2;

	i = 0;
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb *= -1;
	}
	n2 = nb;
	if (n2 > 9)
	{
		i += ft_putnbr(n2 / 10);
		i += ft_putnbr(n2 % 10);
	}
	else
	{
		n2 += '0';
		write(1, &n2, 1);
		i++;
	}
	return (i);
}

void	ft_check(int ac, char **av)
{
	int	i;
	int	j;
	long num;

	i = 1;
	j =  i + 1;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (num == 2147483648)
		{
			write(2, "Error", 5);
			exit (0);
		}
		else
		{
			while (j < i)
			{
				if (ft_atoi(av[i]) == ft_atoi(av[j]))
				{
					write(2, "Error", 5);
					exit (0);
				}
				j++;
			}
		}
		i++;
	}
}

t_list **ft_get_num_a(int ac , char **av, t_list **truck )
{
	int		i;
	int 	j;
	t_list	*new_node;

	i = 1;
	ft_check(ac, av);
	new_node = *truck;
	while (i < ac)
		ft_lstadd_back(&new_node , ft_lstnew(ft_atoi(av[i++])));
	new_node->next = NULL;
	return (truck);
}