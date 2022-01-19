/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:44:03 by midfath           #+#    #+#             */
/*   Updated: 2021/12/20 15:41:05 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_get_num(int ac , char **av)
{
	int		i;
	t_list 	*p;

	i = 1;
	p = NULL;
	t_list	*buffer;

	while (i < ac)
	{
		buffer = ft_lstnew(ft_atoi(av[i]));
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		ft_lstadd_front(&p, buffer);
		i++;
	}
	return (p);
}

void st_swap(t_list *node) //ss && sa && sb
{
	t_list	*dep;
	int		swp;
	
	dep = node;
	dep = dep->next;
	swp = node->content;
	node->content = dep->content;
	dep->content = swp;
}

void	st_push(t_list **src, t_list **dst) // pa && pb && 
{
	t_list *node;

	if (!(*src))
		return ;
	node = *src;
	(*src) = (*src)->next;
	ft_lstadd_front(dst, node);
}

void st_rotate(t_list **head) // Ra && Rb
{
	t_list	*node;

	if (!(*head))
		return ;
	node = *head;
	*head = (*head)->next;
	ft_lstadd_back(head, node);
}

void st_rev_rotate(t_list **node) // rra && rrb && rrr
{
	t_list	*tmp;
	t_list	*end;

	tmp = ft_lstlast(*node);
	end = *node;
	while (end->next->next)
		end = end->next;
	end->next = NULL;
	ft_lstadd_front(node, tmp);

}