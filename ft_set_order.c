/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:42:36 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/05 13:58:23 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initial_order(t_stack	*a, int content)
{
	int	i;

	i = 1;
	while (a->content != content)
	{
		if (a->content > content)
			a->order++;
		else
			i++;
		a = a->next;
	}
	a->order = i;
}

void	ft_set_order(t_stack	*a)
{
	t_stack	*p;

	p = a;
	while (p)
	{
		ft_initial_order(a, p->content);
		p = p->next;
	}
}
