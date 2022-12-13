/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:24:08 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 18:12:32 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (ft_check_one(c) || ft_check_ascend(c))
		return (ft_free_c(&c));
	a = ft_get_a(c, a);
	ft_set_order(a);
	ft_sorting_stack(&a, &b);
	ft_free_all(&a, &b);
}
