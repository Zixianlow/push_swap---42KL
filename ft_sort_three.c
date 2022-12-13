/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:13:33 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/06 20:44:35 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_part2(t_stack **a, int i, int j, int k)
{
	if (i < j && j > k && k < i)
		*a = ft_rule_rev_r(a, 1);
	else if (i > j && j > k)
	{
		ft_rule_s(*a, 1);
		*a = ft_rule_rev_r(a, 1);
	}
}

void	ft_sort_three(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->content;
	j = (*a)->next->content;
	if ((*a)->next->next)
		k = (*a)->next->next->content;
	else
	{
		if (i > j)
			ft_rule_s(*a, 1);
		return ;
	}
	if (j > i && j > k && k > i)
	{
		ft_rule_s(*a, 1);
		ft_rule_r(*a, 1);
	}
	else if (i > j && j < k && k > i)
		ft_rule_s(*a, 1);
	else if (i > j && j < k && k < i)
		ft_rule_r(*a, 1);
	ft_sort_three_part2(a, i, j, k);
}
