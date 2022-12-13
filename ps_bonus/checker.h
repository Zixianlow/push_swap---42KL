/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:36:17 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 19:10:40 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../push_swap.h"

void	ft_do_rule(char *rule, t_stack **a, t_stack **b);
char	*ft_check_rule(char *rule);
char	*ft_set_to_null(char *rule, int i);

#endif