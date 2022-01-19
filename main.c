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
#include <stdio.h>

static void	ft_check(int ac, char **av)
{
	int	i;
	int	j;
	long num;

	i = 1;
	if (ac <= 2)
			exit (0);
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num == 2147483648 || num == -2147483648)
		{
			write(2, "Error", 5);
			exit (0);
		}
		j =  i + 1;
		while (j < ac)
		{
			if (num == ft_atoi(av[j]))
			{
				write(2, "Error", 5);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int main(int  ac, char **av)
{
	int		i;
	t_list	*a;
	t_list	*b;

	ft_check(ac, av);
	i = 0;
	a = ft_get_num(ac , av);
	b = NULL;
	
	printf("\n");
	//st_swap(a);
	// st_push(&a, &b);
	// st_push(&a, &b);
	
	//st_rev_rotate(&a);
    while (a || b)
    {
        if (a)
        {
            printf("%d", a->content);
            a = a->next;
        }
        printf("	|	");
        if (b)
        {
            printf("%d", b->content);
            b = b->next;
        }
        printf("\n");
    }
    printf("-\t\t-\na\t\tb\n");
	// while (a)
	// {
	// 	printf("a = %d\n", a->content);
	// 	a = a->next;
	// }
	// printf("----------\n");
	// while (b)
	// {
	// 	printf("b = %d\n", b->content);
	// 	b = b->next;
	// }
}