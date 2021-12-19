/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:27 by midfath           #+#    #+#             */
/*   Updated: 2021/12/19 11:20:44 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_lst;
	t_list	*buffer;

	new_lst = NULL;
	while (lst)
	{
		buffer = ft_lstnew(f(lst->content));
		if (!buffer)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, buffer);
	}
	return (new_lst);
}

/*
void	*ft_ft(void *str)
{
	int i;
	int	len;
	char	*new_str;

	len = ft_strlen((char *)str);
	new_str = (char *)malloc(len + 1);
	ft_strlcpy(new_str, (char *)str, len + 1);
	i = -1;
	while (new_str[++i])
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
	return (new_str);
}

#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*new_head;

	head = new_head;
	ft_lstadd_back(&head, ft_lstnew("hello"));
	ft_lstadd_back(&head, ft_lstnew("world"));
	ft_lstadd_back(&head, ft_lstnew("1337"));
	new_head = ft_lstmap(head, &ft_ft, &free);
	for(; new_head; new_head = new_head->next)
		printf("%s", (char *)(new_head->content));
	return (0);
}*/
