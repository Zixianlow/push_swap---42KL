/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:40:22 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 14:00:26 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_under_half_part(t_stack *a, int order, int part, int k)
{
	if (order >= ft_sorted_min(a, part, k) - part)
		if (order < ft_sorted_min(a, part, k) - part / 2)
			return (1);
	return (0);
}

void	ft_rotate_b(t_stack **a, t_stack **b, int part, int k)
{
	if ((ft_stack_size(*a) - k) % part < part / 2)
	{
		while (ft_check_under_half_part(*a, (*b)->order, part, k))
		{
			if (ft_check_under_half_part(*a, (*b)->next->order, part, k))
				if ((*b)->next->order > (*b)->next->order)
					ft_rule_s(*b, 2);
			ft_rule_r(*b, 2);
		}
	}
}

void	ft_rev_rotate_b(t_stack **a, t_stack **b, int part, int k)
{
	if ((ft_stack_size(*a) - k) % part == part / 2)
	{
		while (ft_bottom_high(*b, part))
		{
			if (ft_stack_min(*a) != (*a)->order)
			{
				if (ft_last_node_order(*a) != ft_stack_min(*a))
					ft_rule_rev_rr(a, b, 1);
				else
					*b = ft_rule_rev_r(b, 2);
			}
			else
				*b = ft_rule_rev_r(b, 2);
			if ((*b)->order == (*a)->order - 1)
				ft_rule_p(b, a, 2);
		}
	}
}

void	ft_put_back(t_stack **a, t_stack **b, int part)
{
	int	i;
	int	s;
	int	k;

	i = 0;
	k = ft_stack_size(*b) + 3;
	while (k - part > 0)
		k -= part;
	s = ft_last_node_order(*a);
	while (*b)
	{
		i = ft_last_node_order(*a);
		ft_rotate_b(a, b, part, k);
		ft_rev_rotate_b(a, b, part, k);
		ft_put_back_part_a(a, b, s, part);
	}
}

void	ft_put_back_10(t_stack **a, t_stack **b)
{
	int	i;
	int	s;

	i = 0;
	s = ft_last_node_order(*a);
	while (*b)
	{
		i = ft_last_node_order(*a);
		if ((*b)->order < ft_last_node_order(*b))
			ft_rule_r(*b, 2);
		ft_put_back_part_a(a, b, s, 15);
	}
}
