/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:52:50 by midfath           #+#    #+#             */
/*   Updated: 2021/12/20 11:51:59 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(int a)
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
	if (ac < 2)
		exit (0);
	while (i < ac)
	{
		num = ft_up_atoi(av[i]);
		if (num == 2147483648 || num == -2147483648)
			ft_error(1);
		j = i + 1;
		while (j < ac)
		{
			if (num == ft_up_atoi(av[j]))
				ft_error(1);
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
		num = ft_atoi(av[i]);
		ft_lstadd_back(&p, st_newnode((void *)&num));
			i++;
	}
	return (p);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 3;
	a = ft_get_num(ac, av);
	b = NULL;
	st_putitright(&a, &b);
	st_clear(&a);
	st_clear(&b);
}
/*	printf("[%d]\n", st_isready(a));
	//st_trans(&a);
	printf("\n");
	//st_swap_ab(&a ,'a');
	//st_push_ab(&a, &b, 'b');
	//st_rotate_ab(&a, 'a');

    while (a || b)
    {
        if (a)
        {
            printf("%d", *(int *)a->content);
            a = a->next;
        }
        printf("	|	");
        if (b)
        {
            printf("%d", *(int *)b->content);
            b = b->next;
        }
        printf("\n");
   }
    printf("-\t\t-\na\t\tb\n");
}
*/
