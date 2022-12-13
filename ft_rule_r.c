/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:00:03 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 17:45:47 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rule_r(t_stack *a, int type)
{
	while (a->next)
	{
		ft_rule_s(a, 0);
		a = a->next;
	}
	if (type == 1)
		ft_putstr_fd("ra\n", 1);
	else if (type == 2)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rule_rr(t_stack *a, t_stack *b, int type)
{
	if (ft_stack_size(a))
		ft_rule_r(a, 0);
	if (ft_stack_size(b))
		ft_rule_r(b, 0);
	if (type == 1)
		ft_putstr_fd("rr\n", 1);
}
