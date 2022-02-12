/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:57:45 by midfath           #+#    #+#             */
/*   Updated: 2022/02/11 22:00:09 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "get_next_line.h"
# include "../push_swap.h"

void	st_checker(t_list **a, t_list **b);
int		ch_swap_ab(t_list **head);
int		ch_push_ab(t_list **a, t_list **b);
int		ch_rotate_ab(t_list **head);
int		ch_rev_rotate_ab(t_list **node);
int		ch_rrotate_rrr(t_list **a, t_list **b);
int		ch_swap_ss(t_list **a, t_list **b);
int		ch_rotate_rr(t_list **a, t_list **b);
void	swap(t_list **a, t_list **b, char *buff);
void	push(t_list **a, t_list **b, char *buff);
void	rotate(t_list **a, t_list **b, char *buff);
void	rev_rotate(t_list **a, t_list **b, char *buff);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(void);

#endif