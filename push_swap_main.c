/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:52:50 by midfath           #+#    #+#             */
/*   Updated: 2021/12/19 11:22:37 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int  ac, char **av)
{
	int		i;
	t_list	**truck;
	
	
	i = 0;
	truck = ft_get_num_a(ac , av, truck);	
	printf("\n");
    while (truck[0] || truck[1])
    {
        if (truck[0])
        {
            printf("%d", truck[0]->content);
            truck[0] = truck[0]->next;
        }
        printf("    |    ");
        if (truck[1])
        {
            printf("%d", truck[1]->content);
            truck[1] = truck[1]->next;
        }
        printf("\n");
    }
    printf("-\t\t-\na\t\tb\n");
	return (0);
}