/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:28:12 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 19:10:35 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_do_rule(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(rule, "pa", 2))
		ft_rule_p(b, a, 0);
	else if (!ft_strncmp(rule, "pb", 2))
		ft_rule_p(a, b, 0);
	else if (!ft_strncmp(rule, "ra", 2))
		ft_rule_r(*a, 0);
	else if (!ft_strncmp(rule, "rb", 2))
		ft_rule_r(*b, 0);
	else if (!ft_strncmp(rule, "rra", 3))
		*a = ft_rule_rev_r(a, 0);
	else if (!ft_strncmp(rule, "rrb", 3))
		*b = ft_rule_rev_r(b, 0);
	else if (!ft_strncmp(rule, "rrr", 3))
		ft_rule_rev_rr(a, b, 0);
	else if (!ft_strncmp(rule, "rr", 2))
		ft_rule_rr(*a, *b, 0);
	else if (!ft_strncmp(rule, "sa", 2))
		ft_rule_s(*a, 0);
	else if (!ft_strncmp(rule, "sb", 2))
		ft_rule_s(*b, 0);
	else if (!ft_strncmp(rule, "ss", 2))
		ft_rule_ss(*a, *b, 0);
}

char	*ft_check_rule(char *rule)
{
	if (!ft_strncmp(rule, "pa", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "pb", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "ra", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "rb", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "rra", 3))
		rule = ft_set_to_null(rule, 3);
	else if (!ft_strncmp(rule, "rrb", 3))
		rule = ft_set_to_null(rule, 3);
	else if (!ft_strncmp(rule, "rrr", 3))
		rule = ft_set_to_null(rule, 3);
	else if (!ft_strncmp(rule, "rr", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "sa", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "sb", 2))
		rule = ft_set_to_null(rule, 2);
	else if (!ft_strncmp(rule, "ss", 2))
		rule = ft_set_to_null(rule, 2);
	else
		ft_error();
	return (rule);
}

char	*ft_set_to_null(char *rule, int i)
{
	if (rule[i] == '\n')
	{
		rule[i] = '\0';
		return (rule);
	}
	else
		ft_error();
	return (NULL);
}
