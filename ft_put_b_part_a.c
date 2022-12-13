/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_b_part_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:55:30 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 14:00:44 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_int	*ft_set_ps_int(t_ps_int *l, t_stack **a)
{
	l = malloc (sizeof(t_ps_int));
	l->i = ft_stack_size(*a);
	if (l->i > 165)
		l->l = l->i * 0.09;
	else
		l->l = 15;
	l->part = l->l;
	l->part = ft_calc_part(*a, l->l, l->part);
	l->part2 = l->l * 2;
	l->part2 = ft_calc_part(*a, l->l * 2, l->part2);
	if (l->part == l->part2)
		l->part2 = 0;
	l->c = 0;
	return (l);
}

void	ft_choose_rr_or_r(t_stack **a, t_stack **b, t_ps_int *l)
{
	if ((*a)->order > l->part2)
		ft_rule_rr(*a, *b, 1);
	else
		ft_rule_r(*b, 2);
}

void	ft_put_b_rotate_a(t_stack **a, t_stack **b, t_ps_int **l)
{
	if ((*a)->order <= (*l)->part)
	{
		ft_rule_p(a, b, 1);
		if ((*l)->part2 && (*b)->next && (*b)->order <= (*l)->part)
		{
			if ((*l)->part <= (*l)->l)
				ft_choose_rr_or_r(a, b, *l);
		}
		(*l)->c++;
	}
	else if ((*a)->order <= (*l)->part2 && (*a)->order > (*l)->part)
	{
		ft_rule_p(a, b, 1);
		if ((*l)->part2 > 2 * (*l)->l)
			ft_choose_rr_or_r(a, b, *l);
		(*l)->c++;
	}
	else
		ft_rule_r(*a, 1);
}

void	ft_reset_ps_int(t_stack **a, t_stack **b, t_ps_int **l)
{
	if ((*l)->c == (*l)->l * 2)
	{
		(*l)->part = (*l)->part2 + (*l)->l;
		(*l)->part = ft_calc_part(*a, (*l)->l, (*l)->part);
		while ((*l)->c > (*l)->l && (*l)->part2 > (*l)->l + (*l)->l)
		{
			*b = ft_rule_rev_r(b, 2);
			(*l)->c--;
		}
		(*l)->part2 = (*l)->part + (*l)->l;
		(*l)->part2 = ft_calc_part(*a, (*l)->l * 2, (*l)->part2);
		if ((*l)->part == (*l)->part2)
			(*l)->part2 = 0;
		(*l)->c = 0;
	}
}

int	ft_put_b_part(t_stack **a, t_stack **b)
{
	t_ps_int	*l;
	int			part;

	l = NULL;
	l = ft_set_ps_int(l, a);
	while (l->i > 3)
	{
		ft_put_b_rotate_a(a, b, &l);
		ft_reset_ps_int(a, b, &l);
		l->i = ft_stack_size(*a);
	}
	while (l->c > l->l && l->part2 > l->l + l->l)
	{
		*b = ft_rule_rev_r(b, 2);
		l->c--;
	}
	part = l->l;
	free(l);
	return (l->l);
}
