/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:44:27 by midfath           #+#    #+#             */
/*   Updated: 2022/02/07 11:44:27 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_max(t_list *head)
{
	t_list	*max;

	max = NULL;
	while (head)
	{
		if (!max || *(int *)max->content < *(int *)head->content)
			max = head;
		head = head->next;
	}
	return (max);
}

t_list	*lst_min(t_list *head)
{
	t_list	*min;

	min = NULL;
	while (head)
	{
		if (!min || *(int *)min->content > *(int *)head->content)
			min = head;
		head = head->next;
	}
	return (min);
}

size_t	lst_find(t_list *head, void *content)
{
	size_t	i;

	i = 0;
	while (head)
	{
		if (!ft_memcmp(head->content, content, sizeof(int)))
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

void	lst_put_at(t_list **stack, size_t index, void *num)
{
	int		i;
	t_list	*start;

	i = 0;
	start = *stack;
	while (start)
	{
		if (i == index)
		{
			free(start->content);
			start->content = NULL;
			start->content = malloc(sizeof(int));
			ft_memcpy(start->content, num, sizeof(int));
			break ;
		}
		i++;
		start = start->next;
	}
}

t_list	*lst_get(t_list *head, size_t index)
{
	size_t	i;

	i = 0;
	while (head)
	{
		if (i == index)
			return (head);
		i++;
		head = head->next;
	}
	return (NULL);
}
