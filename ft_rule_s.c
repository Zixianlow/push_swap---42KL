/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:00:00 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 17:45:20 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rule_s(t_stack *a, int type)
{
	int	temp;
	int	order;

	if (!(a->next))
		return ;
	temp = a->content;
	order = a->order;
	a->content = a->next->content;
	a->order = a->next->order;
	a = a->next;
	a->content = temp;
	a->order = order;
	if (type == 1)
		ft_putstr_fd("sa\n", 1);
	else if (type == 2)
		ft_putstr_fd("sb\n", 1);
}

void	ft_rule_ss(t_stack *a, t_stack *b, int type)
{
	if (ft_stack_size(a) > 1)
		ft_rule_s(a, 0);
	if (ft_stack_size(b) > 1)
		ft_rule_s(b, 0);
	if (type == 1)
		ft_putstr_fd("ss\n", 1);
}
