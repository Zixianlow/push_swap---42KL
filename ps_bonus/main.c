/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:53:21 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/08 13:38:56 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker_input(t_stack **a, t_stack **b)
{
	char	*rule;

	while (1)
	{
		rule = get_next_line(0);
		if (!rule)
			break ;
		rule = ft_check_rule(rule);
		ft_do_rule(rule, a, b);
	}
}

int	ft_chk_ascend_stack(t_stack *a)
{
	while (a)
	{
		if (a->next)
			if (a->next->order < a->order)
				return (0);
		a = a->next;
	}
	return (1);
}

void	ft_checker_result(t_stack *a, t_stack *b)
{
	if (ft_chk_ascend_stack(a) && !ft_stack_size(b))
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	ft_checker_max(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (ft_ps_atoi(c[i]) < -2147483648)
			ft_error();
		else if (ft_ps_atoi(c[i]) > 2147483647)
			ft_error();
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**c;
	char	*s;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!ft_chk_not_num(av))
		ft_error();
	s = ft_get_arguments(ac, av);
	c = ft_split(s, ' ');
	if (ft_check_dup(&c))
		ft_error();
	ft_checker_max(c);
	a = ft_get_a(c, a);
	ft_set_order(a);
	ft_checker_input(&a, &b);
	ft_checker_result(a, b);
	ft_free_all(&a, &b);
}
