/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:57:45 by midfath           #+#    #+#             */
/*   Updated: 2022/02/08 10:27:49 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "../push_swap.h" 
# include "get_next_line.h"

int	st_checker(t_list **a, t_list **b);
int	st_rules_check(char *buff);


#endif