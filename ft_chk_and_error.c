/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_and_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:26:25 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 19:42:05 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chk_not_sp_num(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_chk_not_num(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_chk_not_sp_num(av[i][j++]))
				return (0);
	}
	if (i == 1)
		return (0);
	return (1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}
