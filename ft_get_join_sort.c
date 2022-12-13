/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_join_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:52:57 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 13:54:26 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rearrange(t_stack **a)
{
	int	i;
	int	c;

	i = ft_stack_size(*a);
	if ((*a)->order)
		c = (*a)->order - 1;
	else
		c = 0;
	while (c && c != i)
	{
		if (c <= i / 2)
		{
			*a = ft_rule_rev_r(a, 1);
			c--;
		}
		else
		{
			ft_rule_r(*a, 1);
			c++;
		}
	}
}

void	ft_sorting_stack(t_stack **a, t_stack **b)
{
	int	i;
	int	k;

	i = ft_stack_size(*a);
	k = ft_put_b_part(a, b);
	ft_sort_three(a);
	if (i <= 10)
		ft_put_back_10(a, b);
	else
		ft_put_back(a, b, k);
	ft_rearrange(a);
}

char	*ft_join_arg(int ac, char **av)
{
	int		i;
	char	*s;
	char	*d;

	i = 1;
	s = ft_strdup("");
	d = ft_strdup("");
	while (ac > 1)
	{
		free(d);
		d = ft_strjoin(s, " ");
		free(s);
		s = ft_strdup(d);
		free(d);
		d = ft_strjoin(s, av[i]);
		free(s);
		s = ft_strdup(d);
		i++;
		ac--;
	}
	free(s);
	return (d);
}

char	*ft_get_arguments(int ac, char **av)
{
	char	*s;

	if (ac > 2)
		s = ft_join_arg(ac, av);
	else
		s = av[1];
	return (s);
}
