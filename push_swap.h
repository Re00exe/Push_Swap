/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:56:28 by midfath           #+#    #+#             */
/*   Updated: 2021/12/20 15:41:18 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
/***************************e**LIBFT***********************************/
typedef struct  s_list
{
	int			content;
	struct s_list *next;
}t_list;

int		ft_isdigit(int c);
long	ft_atoi(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
t_list	*ft_lstnew(int content);
int	ft_lstsize(t_list *lst);
/*********************************PUSH_SWAP***********************************/

t_list *ft_get_num(int ac , char **av);
void st_swap(t_list *node);
void	st_push(t_list **src, t_list **dst);
void st_rotate(t_list **node);
void st_rev_rotate(t_list **node);

#endif
