/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:29:20 by midfath           #+#    #+#             */
/*   Updated: 2021/12/19 11:08:52 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*buff;

	while (*lst)
	{		
		buff = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = buff;
	}
}
