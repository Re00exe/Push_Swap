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
# include "libft/libft.h"
/*********************************PUSH_SWAP***********************************/

/*******sorting_fct.c********************/
long	ft_up_atoi(char *str);
int		st_to_lift(t_list **stack, void*content, char c);
void	*st_pop_out(t_list **stack);
int		st_new_push(t_list **stack, void *new);
void	st_clear(t_list **stack);
/*********************************PUSH_SWAP***********************************/
/********push_swap_utils.c****************************/
int		st_swap_ab(t_list **head, char c);
int		st_push_ab(t_list **src, t_list **dst, char c);
int		st_rotate_ab(t_list **head, char c);
int		st_rev_rotate_ab(t_list **node, char c);
int		st_rrotate_rrr(t_list **a, t_list **b);
/*********************************PUSH_SWAP***********************************/
/********lst_options.c***************************/
t_list	*lst_max(t_list *head);
t_list	*lst_min(t_list *head);
size_t	lst_find(t_list *head, void *content);
void	lst_put_at(t_list **stack, size_t index, void *num);
t_list	*lst_get(t_list *head, size_t index);
/*********************************PUSH_SWAP***********************************/
/*******stack_utils.c************************************************/
int		st_isready(t_list *head);
void	st_trans(t_list **stack);
t_list	*st_newnode(void *num);
int		st_swap_ss(t_list **a, t_list **b);
int		st_rotate_rr(t_list **a, t_list **b);
/*********************************PUSH_SWAP***********************************/
/*******ssorting.c******************************/
int		st_putitright(t_list **a, t_list **b);
void	st_smallsorting(t_list **a, t_list **b);
int		ft_nbrlen(int n, int base);
int		st_radix(t_list **a, t_list **b, int shifter);
int		st_checkorder(t_list *a, t_list *b, char c);

#endif
