/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:42:12 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/06 20:44:57 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bottom_high(t_stack *b, int part)
{
	int	i;

	i = 0;
	while (b->next)
		b = b->next;
	if (b->order > part)
		return (1);
	return (0);
}

int	ft_sorted_min(t_stack *a, int part, int k)
{
	int	max;
	int	size;
	int	i;

	max = ft_stack_max(a) - k + 1;
	size = ft_stack_size(a);
	i = 0;
	while (size - k >= part)
	{
		size -= part;
		i++;
	}
	while (i > 0 && max >= part)
	{
		max -= part;
		i--;
	}
	return (max);
}

int	ft_swap_better(t_stack *a, t_stack *b, int part)
{
	if (a->next && b && b->next && b->next->next)
	{
		if (b->next->order - b->order > part / 2)
			return (1);
		if (b->next->order > b->order && a->order > b->next->order)
			return (1);
		if (b->next->order > b->order && b->order > a->order)
			return (1);
	}
	return (0);
}

void	ft_put_back_part_a(t_stack **a, t_stack **b, int s, int part)
{
	int	i;

	i = ft_last_node_order(*a);
	if (ft_swap_better(*a, *b, part))
		ft_rule_s(*b, 2);
	else if ((*b)->order < (*a)->order && i == s)
		ft_rule_p(b, a, 2);
	else if ((*b)->order > i && (*b)->order < (*a)->order)
		ft_rule_p(b, a, 2);
	else if ((*b)->order > (*a)->order && (*b)->order < i)
		ft_rule_r(*a, 1);
	else if ((*b)->order > (*a)->order && (*b)->order > i)
		ft_rule_r(*a, 1);
	else
		*a = ft_rule_rev_r(a, 1);
}

int	ft_calc_part(t_stack *a, int increment, int part)
{
	int	i;

	i = ft_stack_size(a);
	if (i - increment >= 3)
		return (part);
	while (i - increment < 3)
	{
		increment--;
		part--;
	}
	return (part);
}
