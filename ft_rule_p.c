/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:00:05 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/06 18:28:24 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rule_p_free_a(t_stack **a)
{
	t_stack	*temp;

	if (!(*a)->next)
	{
		free(*a);
		*a = 0;
	}
	else
	{
		temp = (*a);
		*a = (*a)->next;
		free(temp);
		(*a)->prev = NULL;
	}
	return (*a);
}

void	ft_rule_p(t_stack **a, t_stack **b, int type)
{
	t_stack	*c;

	if (!*a)
		return ;
	c = (t_stack *) malloc(sizeof(t_stack));
	c->prev = NULL;
	c->content = (*a)->content;
	c->order = (*a)->order;
	c->next = *b;
	if (!*b)
		*b = c;
	else
	{
		while ((*b)->prev)
			*b = (*b)->prev;
		(*b)->prev = c;
		*b = (*b)->prev;
	}
	*a = ft_rule_p_free_a(a);
	if (type == 1)
		ft_putstr_fd("pb\n", 1);
	else if (type == 2)
		ft_putstr_fd("pa\n", 1);
}
