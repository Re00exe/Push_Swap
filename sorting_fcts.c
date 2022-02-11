/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_fcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:56:01 by midfath           #+#    #+#             */
/*   Updated: 2021/12/18 17:07:25 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_up_atoi(char *str)
{
	int				i;
	unsigned long	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	if (str[i] || nb > INT_MAX)
		return (2147483648);
	else
		return (nb * sign);
}

int	st_to_lift(t_list **stack, void*content, char c)
{
	ssize_t	index;
	void	*tmp;

	tmp = malloc(sizeof(int));
	if (!tmp)
		return (0);
	ft_memcpy(tmp, content, sizeof(int));
	index = lst_find(*stack, content);
	if (*(int *)stack[0]->content != *(int *)tmp && index != -1)
	{
		while (ft_memcmp(tmp, stack[0]->content, sizeof(int)))
		{
			if (index > (ft_lstsize(*stack) - 1) / 2)
				st_rev_rotate_ab(stack, c);
			else
				st_rotate_ab(stack, c);
		}
	}
	free(tmp);
	return (0);
}

void	*st_pop_out(t_list **stack)
{
	void	*node;
	t_list	*head;

	head = NULL;
	if (!stack || !stack[0])
		return (NULL);
	head = *stack;
	if (head->next)
	{
		*stack = head->next;
		node = head->content;
		free(head);
		return (node);
	}
	node = head->content;
	free(head);
	*stack = NULL;
	return (node);
}

int	st_new_push(t_list **stack, void *new)
{
	t_list	*node;

	node = st_newnode(new);
	if (!node)
		return (0);
	ft_lstadd_front(stack, node);
	return (1);
}
